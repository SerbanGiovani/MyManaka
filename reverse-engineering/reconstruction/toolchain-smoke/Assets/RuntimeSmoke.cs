using System;
using System.IO;
using UnityEngine;
namespace REAToolchain {
public class RuntimeSmoke:MonoBehaviour {
 [Serializable]public class Receipt {public string engineVersion,scene;public int frames;public bool passed;public string scope="compiler/build/player startup only; no original assets or gameplay equivalence";}
 int frames;
 void Update(){if(++frames<5)return;var args=Environment.GetCommandLineArgs();int i=Array.IndexOf(args,"-reaProof");if(i<0||i+1>=args.Length){enabled=false;return;}
  bool passed=gameObject.name=="CompilerSmokeCube"&&GetComponent<MeshRenderer>()!=null;
  File.WriteAllText(Path.GetFullPath(args[i+1]),JsonUtility.ToJson(new Receipt{engineVersion=Application.unityVersion,scene=gameObject.scene.name,frames=frames,passed=passed},true));Application.Quit(passed?0:2);
 }
}
}
