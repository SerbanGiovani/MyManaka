"""Plan focused native queries for the natural NPC visibility producer."""
import json
import sqlite3
from pathlib import Path
from prepare_batch import label

HERE=Path(__file__).resolve().parent
if __name__=='__main__':
    plan=json.loads((HERE/'symbols/natural-menu-time.plan.json').read_text(encoding='utf8'))
    connection=sqlite3.connect((HERE/'.cache/methods.sqlite').as_uri()+'?mode=ro',uri=True)
    connection.row_factory=sqlite3.Row
    rows=[dict(connection.execute('select * from methods where id=?',(i,)).fetchone())
          for i in [16926,16927,17166,17167,17168,17169,17172,17173,17174,17181]]
    connection.close()
    plan.update(name='notification-culling',output_directory=str(HERE/'evidence/notification-culling'),
       functions=[dict(metadata_id=r['id'],qualified_name=r['qualified_name'],token=hex(r['token']),
                       va=r['va'],file_offset=r['file_offset'],label=label(r),file_stem=f"{r['id']}-{r['token']:08x}",
                       operations=['procedure_pseudo_code']) for r in rows])
    plan['limitations']=['Metadata-derived coordinates, bounded direct pseudocode; runtime evidence is recorded separately.']
    dest=HERE/'symbols/notification-culling.plan.json'
    dest.write_text(json.dumps(plan,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(dest)
