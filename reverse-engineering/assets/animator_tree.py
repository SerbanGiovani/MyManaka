"""Decode the selected shipped type trees, retaining scalar/array byte spans.

Only schemas present in the pinned bundle are accepted. Common-buffer aliases
used here remain numeric unless their meaning is needed by the decoder.
"""
from inspect_resources import Reader

ALIASES = {"$common:427": "m_Name", "$common:49": "Array", "$common:106": "data",
           "$common:155": "first", "$common:778": "second",
           "$common:374": "m_GameObject", "$common:349": "m_Enabled",
           "$common:519": "m_Type", "$common:387": "m_Index"}
FORMATS = {"$common:222": "i", "$common:934": "I", "$common:814": "q",
           "$common:161": "f", "$common:76": "?", "$common:81": "B", "$common:928": "B"}


class TreeDecoder:
    def __init__(self, tree):
        self.tree = tree
        self.children = {i: [] for i in range(len(tree))}
        stack = []
        for i, node in enumerate(tree):
            while stack and tree[stack[-1]]["level"] >= node["level"]:
                stack.pop()
            if stack:
                self.children[stack[-1]].append(i)
            stack.append(i)

    def decode(self, raw):
        reader = Reader(raw)
        spans = []

        def visit(index, path):
            node = self.tree[index]
            start = reader.position
            children = self.children[index]
            if node["type"] == "$common:840":
                value = reader.aligned_string()
            elif node["type_flags"] & 1:
                assert len(children) == 2
                count = reader.number("i")
                assert 0 <= count <= 1_000_000, (path, count)
                value = [visit(children[1], f"{path}[{i}]") for i in range(count)]
            elif children:
                values = [(ALIASES.get(self.tree[c]["name"], self.tree[c]["name"]),
                           visit(c, path + "/" + ALIASES.get(self.tree[c]["name"], self.tree[c]["name"]))) for c in children]
                assert len({k for k, _ in values}) == len(values), (index, path)
                value = values[0][1] if len(values) == 1 and values[0][0] in ("Array", "data") else dict(values)
            else:
                fmt = FORMATS.get(node["type"])
                assert fmt, (index, node)
                value = reader.number(fmt)
            value_end = reader.position
            if node["meta_flags"] & 0x4000:
                reader.align()
            spans.append({"tree_index": index, "path": path, "serialized_offset": start,
                          "value_end": value_end, "serialized_end": reader.position})
            return value

        result = visit(0, "root")
        assert reader.position == len(raw), (reader.position, len(raw))
        return {"value": result, "spans": spans, "bytes_consumed": reader.position,
                "end_of_object_verified": True}
