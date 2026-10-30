import sys,json
from pathlib import Path
sys.dont_write_bytecode=True
sys.path.insert(0,str(Path('reverse-engineering/salt').resolve()))
from scene_evidence import build
r=build(batch_prefix='interaction-NONE-',reuse_method_ids={15889,16710,16712,16720,14421,14462,14463,14461,14489,14536,14553,14811,14831,14908,14903,14899,15817,15820,15821,15822,15823,17375,17376,17377,17379,17381,16342},extra_type_names=('DropItemType','DroppedItemController','InteractAreaController','PlayerStateModel','PlayerAction','InputData'))
Path('reverse-engineering/reconstruction/interaction-evidence/reused-native-contract.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print([(u['va'],u.get('method_id'),u.get('method_name'),u.get('type_name')) for u in r['usages'] if u['va'] in ['0x182d5ca10','0x182d5ca08','0x182d5c9d8','0x182d5ca38']])
