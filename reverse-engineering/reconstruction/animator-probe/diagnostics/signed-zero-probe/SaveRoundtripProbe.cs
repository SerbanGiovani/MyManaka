using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using UnityEditor;
using UnityEngine;

namespace ReconstructedManaka.Editor {
public static class SaveRoundtripProbe {
 [Serializable] public class FloatValue { public float value; }
 [Serializable] public class DoubleValue { public double value; }
 [Serializable] public class DoubleVector { public double x,y,z,w; }
 [Serializable] public class DoubleSave { public DoubleVector position,rotation; public double bodyPaintRemaining; }
 [Serializable] public class Component { public string field,expectedBits,nativeBits,doubleDtoBits; public float expected,native,doubleDto; }
 [Serializable] public class Case { public string bits,json,rJson,nativeBits,rBits,dtoBits; public float expected,nativeLong,nativeRoundTrip,dtoDouble,singleParse,doubleParse; public bool longExact,rExact,dtoExact,singleExact,doubleExact; }
 [Serializable] public class PoseCase { public string name; public Component[] components; public string json; public bool numericEqual,bitEqual; }
 [Serializable] public class Receipt { public string editorVersion,sourceSavePath,exception; public Component[] components; public PoseCase[] yawCases; public int randomCases,nativeLongFailures,nativeRFailures,doubleDtoFailures,singleParseFailures,doubleParseFailures; public Case[] examples; }
 static string Arg(string key) { var a=Environment.GetCommandLineArgs();int p=Array.IndexOf(a,key);return p<0||p+1>=a.Length?null:a[p+1]; }
 static string Bits(float value) { return BitConverter.ToUInt32(BitConverter.GetBytes(value),0).ToString("x8"); }
 static Component Compare(string name,float expected,float native,double dto) { return new Component{field=name,expected=expected,native=native,doubleDto=(float)dto,expectedBits=Bits(expected),nativeBits=Bits(native),doubleDtoBits=Bits((float)dto)}; }
 public static void Run() {
  var r=new Receipt{editorVersion=Application.unityVersion,sourceSavePath=Arg("-savePath")};string output=Arg("-probeOutput");Directory.CreateDirectory(Path.GetDirectoryName(output));
  try {
   string text=File.ReadAllText(r.sourceSavePath);var native=JsonUtility.FromJson<SaveState>(text);var dto=JsonUtility.FromJson<DoubleSave>(text);
   var list=new List<Component>{Compare("position.x",1.938629f,native.position.x,dto.position.x),Compare("position.y",9.971857e-05f,native.position.y,dto.position.y),Compare("position.z",.640309155f,native.position.z,dto.position.z),Compare("rotation.x",0,native.rotation.x,dto.rotation.x),Compare("rotation.y",-.673059344f,native.rotation.y,dto.rotation.y),Compare("rotation.z",0,native.rotation.z,dto.rotation.z),Compare("rotation.w",.7395885f,native.rotation.w,dto.rotation.w),Compare("bodyPaintRemaining",118.798912f,native.bodyPaintRemaining,dto.bodyPaintRemaining)};
   // SaveStore uses FromJsonOverwrite; verify that exact path separately.
   var overwritten=new SaveState();JsonUtility.FromJsonOverwrite(text,overwritten);list.Add(Compare("overwrite.rotation.y",-.673059344f,overwritten.rotation.y,dto.rotation.y));list.Add(Compare("overwrite.position.y",9.971857e-05f,overwritten.position.y,dto.position.y));r.components=list.ToArray();
   var yawCases=new List<PoseCase>();var actor=new GameObject("Quaternion probe");
   foreach(float yaw in new[]{-180f,-135f,-90f,-84.6f,-45f,-.1f,0f,.1f,45f,90f,135f,180f}){
    Vector3 direction=Quaternion.Euler(0,yaw,0)*Vector3.forward;actor.transform.rotation=Quaternion.RotateTowards(Quaternion.Euler(0,9.6f,0),Quaternion.LookRotation(direction),420f);Quaternion q=actor.transform.rotation;
    string json=JsonUtility.ToJson(new SaveState{rotation=q});Quaternion restored=JsonUtility.FromJson<SaveState>(json).rotation;
    var c=new[]{Compare("x",q.x,restored.x,restored.x),Compare("y",q.y,restored.y,restored.y),Compare("z",q.z,restored.z,restored.z),Compare("w",q.w,restored.w,restored.w)};
    yawCases.Add(new PoseCase{name="yaw "+yaw.ToString("R",CultureInfo.InvariantCulture),json=json,components=c,numericEqual=q.x==restored.x&&q.y==restored.y&&q.z==restored.z&&q.w==restored.w,bitEqual=c.All(component=>component.expectedBits==component.nativeBits)});
   }UnityEngine.Object.DestroyImmediate(actor);r.yawCases=yawCases.ToArray();
   var values=new List<float>{BitConverter.ToSingle(BitConverter.GetBytes(0x80000000u),0),1.938629f,9.971857e-05f,.640309155f,-.673059344f,.7395885f,118.798912f,0,1,-1,float.MaxValue,float.MinValue,float.Epsilon};var random=new System.Random(1793383354);var bytes=new byte[4];
   for(int i=0;i<10000;i++){random.NextBytes(bytes);float value=BitConverter.ToSingle(bytes,0);if(!float.IsNaN(value)&&!float.IsInfinity(value))values.Add(value);}
   var examples=new List<Case>();foreach(float value in values) {
    string json=JsonUtility.ToJson(new FloatValue{value=value});string token=Regex.Match(json,"\\\"value\\\"\\s*:\\s*([^}]+)").Groups[1].Value;string roundTrip="{\"value\":"+value.ToString("R",CultureInfo.InvariantCulture)+"}";
    var c=new Case{bits=Bits(value),json=json,rJson=roundTrip,expected=value,nativeLong=JsonUtility.FromJson<FloatValue>(json).value,nativeRoundTrip=JsonUtility.FromJson<FloatValue>(roundTrip).value,dtoDouble=(float)JsonUtility.FromJson<DoubleValue>(json).value,singleParse=float.Parse(token,NumberStyles.Float,CultureInfo.InvariantCulture),doubleParse=(float)double.Parse(token,NumberStyles.Float,CultureInfo.InvariantCulture)};
    c.nativeBits=Bits(c.nativeLong);c.rBits=Bits(c.nativeRoundTrip);c.dtoBits=Bits(c.dtoDouble);c.longExact=Bits(value)==Bits(c.nativeLong);c.rExact=Bits(value)==Bits(c.nativeRoundTrip);c.dtoExact=Bits(value)==Bits(c.dtoDouble);c.singleExact=Bits(value)==Bits(c.singleParse);c.doubleExact=Bits(value)==Bits(c.doubleParse);r.randomCases++;
    if(!c.longExact)r.nativeLongFailures++;if(!c.rExact)r.nativeRFailures++;if(!c.dtoExact)r.doubleDtoFailures++;if(!c.singleExact)r.singleParseFailures++;if(!c.doubleExact)r.doubleParseFailures++;
    if(examples.Count<20&&(!c.longExact||!c.rExact||!c.dtoExact||!c.singleExact||!c.doubleExact))examples.Add(c);
   }r.examples=examples.ToArray();
  }catch(Exception ex){r.exception=ex.ToString();}
  File.WriteAllText(output,JsonUtility.ToJson(r,true));EditorApplication.Exit(string.IsNullOrEmpty(r.exception)?0:2);
 }
}
}
