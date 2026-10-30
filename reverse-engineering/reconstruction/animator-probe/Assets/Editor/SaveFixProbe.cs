using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace ReconstructedManaka.Editor {
public static class SaveFixProbe {
 [Serializable] public class Receipt { public string editorVersion,policy,exception; public bool oldMinimumRead,failedRoundRead,allWritesReadExact,allNumericValuesUnchanged; public int cases,negativeZeroCases,normalizedComponents; public Dictionary<string,int> unused; }
 static string Arg(string key) { var a=Environment.GetCommandLineArgs();int i=Array.IndexOf(a,key);return i<0||i+1>=a.Length?null:a[i+1]; }
 static void Require(bool value,string text) { if(!value)throw new Exception(text); }
 public static void Run() {
  string output=Arg("-probeOutput");Directory.CreateDirectory(Path.GetDirectoryName(output));var r=new Receipt{editorVersion=Application.unityVersion,policy=SaveStore.FloatEqualityPolicy,allWritesReadExact=true,allNumericValuesUnchanged=true};GameObject actor=null;
  try {
   SaveState seed;string error;var seedStore=new SaveStore(Path.Combine(Path.GetDirectoryName(output),"unused-profile"));Require(seedStore.TryImportSeed(Arg("-seed"),out seed,out error),error);
   SaveState old;Require(new SaveStore(Path.GetDirectoryName(Arg("-oldSave"))).TryRead(out old,out error),error);r.oldMinimumRead=true;
   Require(new SaveStore(Path.GetDirectoryName(Arg("-failedSave"))).TryRead(out old,out error),error);r.failedRoundRead=true;
   string directory=Path.Combine(Path.GetDirectoryName(output),"written-profile");Require(!Directory.Exists(directory),"Keep existing probe writes");var store=new SaveStore(directory);string writer=Guid.NewGuid().ToString("N");
   actor=new GameObject("Signed zero save regression");var rotations=new List<Quaternion>();float negativeZero=BitConverter.ToSingle(BitConverter.GetBytes(0x80000000u),0);
   rotations.Add(new Quaternion(negativeZero,-.673059344f,negativeZero,.7395885f));
   rotations.Add(new Quaternion(0,-.673059344f,0,.7395885f));
   foreach(float yaw in new[]{9.6f,99.6f,189.6f,279.6f,9.6f,189.6f,99.6f,279.6f,-84.6f,135f,-135f,9.6f})for(int step=0;step<30;step++){
    actor.transform.rotation=Quaternion.RotateTowards(actor.transform.rotation,Quaternion.LookRotation(Quaternion.Euler(0,yaw,0)*Vector3.forward),7f);rotations.Add(actor.transform.rotation);
   }
   foreach(Quaternion rotation in rotations) {
    SaveState state=JsonUtility.FromJson<SaveState>(JsonUtility.ToJson(seed));state.position=new Vector3(1.938629f,9.971857e-05f,.640309155f);state.rotation=rotation;state.savedProcessGuid=writer;
    Vector3 p=state.position;Quaternion q=state.rotation;float paint=state.bodyPaintRemaining;
    int changed=SaveStore.CanonicalizeSignedZero(state);if(changed>0)r.negativeZeroCases++;r.normalizedComponents+=changed;
    Require(state.position.x==p.x&&state.position.y==p.y&&state.position.z==p.z&&state.rotation.x==q.x&&state.rotation.y==q.y&&state.rotation.z==q.z&&state.rotation.w==q.w&&state.bodyPaintRemaining==paint,"Canonicalization changed a numeric value");
    store.Write(state);SaveState restored;Require(store.TryRead(out restored,out error),error);string mismatch;Require(SaveStore.SameFloatBits(state,restored,out mismatch),mismatch);Require(restored.revision==++r.cases,"Revision did not advance");
   }
  }catch(Exception ex){r.exception=ex.ToString();r.allWritesReadExact=false;}
  finally{if(actor)UnityEngine.Object.DestroyImmediate(actor);File.WriteAllText(output,JsonUtility.ToJson(r,true));}
  EditorApplication.Exit(string.IsNullOrEmpty(r.exception)?0:2);
 }
}
}
