/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#ifdef WITH_JVMTI
#include "jvmti.h"
#endif
/* Header for class de_uni_hildesheim_sse_wifi_AccessPointData */

#ifndef _Included_de_uni_hildesheim_sse_wifi_AccessPointData
#define _Included_de_uni_hildesheim_sse_wifi_AccessPointData
#ifdef __cplusplus
extern "C" {
#endif

// lifecycle

JNIEXPORT jint JNICALL JNI_OnLoad
  (JavaVM *, void *);
JNIEXPORT void JNICALL JNI_OnUnload
  (JavaVM *, void *);
  
#ifdef VAR_WIFI_DATA  
JNIEXPORT jobjectArray JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_gatherWifiSignals0
  (JNIEnv *env, jclass c, jint timeout);
#endif

// screen

#ifdef VAR_SCREEN_DATA
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_ScreenDataGatherer_getScreenWidth0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_ScreenDataGatherer_getScreenHeight0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_ScreenDataGatherer_getScreenResolution0
  (JNIEnv *, jclass);
#endif

// main memory

#ifdef VAR_MEMORY_DATA
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_getMemoryCapacity0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_getCurrentMemoryAvail0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_getCurrentMemoryUse0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_redefineMultiClasses0
  (JNIEnv *, jclass, jobjectArray, jobjectArray);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_redefineClasses0
  (JNIEnv *, jclass, jobjectArray, jobjectArray);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_redefineClass0
  (JNIEnv *, jclass, jclass, jbyteArray);
JNIEXPORT void JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_recordUnallocation0
  (JNIEnv *, jclass, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_recordUnallocation1
  (JNIEnv *, jclass, jobject, jlong, jint, jobjectArray);
JNIEXPORT void JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_recordUnallocation2
  (JNIEnv *, jclass, jlong, jlong, jstring);
JNIEXPORT void JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_recordUnallocation3
  (JNIEnv *, jclass, jlong, jlong, jint, jobjectArray);
JNIEXPORT void JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_recordUnallocation4
  (JNIEnv *, jclass, jlong);
JNIEXPORT void JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_setReceiver0
  (JNIEnv *, jclass, jobject);
#endif
#ifdef VAR_OBJECT_SIZE
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_MemoryDataGatherer_getObjectSize0
  (JNIEnv *, jclass, jobject);
#endif

JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_supportsJVMTI0
  (JNIEnv *, jclass);

// processor 

#ifdef VAR_PROCESSOR_DATA
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessorDataGatherer_getNumberOfProcessors0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessorDataGatherer_getMaxProcessorSpeed0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessorDataGatherer_getCurrentProcessorSpeed0
  (JNIEnv *, jclass);
JNIEXPORT jdouble JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessorDataGatherer_getCurrentSystemLoad0
  (JNIEnv *, jclass);
#endif

// volumes

#ifdef VAR_VOLUME_DATA
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_VolumeDataGatherer_getVolumeCapacity0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_VolumeDataGatherer_getCurrentVolumeAvail0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_VolumeDataGatherer_getCurrentVolumeUse0
  (JNIEnv *, jclass);
#endif

// network

#ifdef VAR_NETWORK_DATA
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_NetworkDataGatherer_getCurrentNetSpeed0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_NetworkDataGatherer_getMaxNetSpeed0
  (JNIEnv *, jclass);
#endif

// power

#ifdef VAR_ENERGY_DATA
JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_BatteryDataGatherer_hasSystemBattery0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_BatteryDataGatherer_getBatteryLifePercent0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_BatteryDataGatherer_getBatteryLifeTime0
  (JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_de_uni_1hildesheim_sse_system_android_BatteryDataGatherer_getPowerPlugStatus0
  (JNIEnv *, jclass);
#endif

// this process

#ifdef VAR_CURRENT_PROCESS_DATA
JNIEXPORT jstring JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessID0
  (JNIEnv *, jclass);
#ifdef VAR_IO_DATA
JNIEXPORT jobject JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessIoRead0
  (JNIEnv *, jclass);
#endif
#ifdef VAR_MEMORY_DATA
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessMemoryUse0
  (JNIEnv *, jclass);
#endif
#ifdef VAR_TIME_DATA
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessUserTimeTicks0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessKernelTimeTicks0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessSystemTimeTicks0
  (JNIEnv *, jclass);
//JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessCycleTimeTicks0
//  (JNIEnv *, jclass);
#endif
#ifdef VAR_LOAD_DATA
JNIEXPORT jdouble JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getCurrentProcessProcessorLoad0
  (JNIEnv *, jclass);
#endif
#endif

#ifdef VAR_DEBUG
//JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_getLastError
//  (JNIEnv *, jclass);
  
//JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_getLastLoadError
//  (JNIEnv *, jclass);
#endif
  
// arbitrary process
#ifdef VAR_ARBITRARY_PROCESS_DATA
JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getProcessAlive0
  (JNIEnv *, jclass, jstring);
#ifdef VAR_IO_DATA
JNIEXPORT jobject JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getProcessIoRead0
  (JNIEnv *, jclass, jstring);
#endif
#ifdef VAR_MEMORY_DATA
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getProcessMemoryUse0
  (JNIEnv *, jclass, jstring);
#endif
#ifdef VAR_TIME_DATA
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getProcessUserTimeTicks0
  (JNIEnv *, jclass, jstring);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getProcessKernelTimeTicks0
  (JNIEnv *, jclass, jstring);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getProcessSystemTimeTicks0
  (JNIEnv *, jclass, jstring);
#endif
#ifdef VAR_LOAD_DATA
JNIEXPORT jdouble JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getProcessProcessorLoad0
  (JNIEnv *, jclass, jstring);
#endif
#endif
// all processes

#ifdef VAR_ALL_PROCESSES_DATA
#ifdef VAR_IO_DATA
JNIEXPORT jobject JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_getAllProcessesIo0
  (JNIEnv *, jclass);
JNIEXPORT jobject JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_getAllProcessesIo0
  (JNIEnv *, jclass);
#ifdef VAR_ARBITRARY_PROCESS_DATA
JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_isNetworkIoDataIncluded0
  (JNIEnv *, jclass, jboolean);
JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_ProcessDataGatherer_isFileIoDataIncluded0
  (JNIEnv *, jclass, jboolean);
#endif
#ifdef VAR_CURRENT_PROCESS_DATA
JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_isNetworkIoDataIncluded0
  (JNIEnv *, jclass, jboolean);
JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_ThisProcessDataGatherer_isFileIoDataIncluded0
  (JNIEnv *, jclass, jboolean);
#endif
#endif
#endif

#ifdef ANDROID
JNIEXPORT jboolean JNICALL Java_de_uni_1hildesheim_sse_system_android_ThreadDataGatherer_supportsCpuThreadTiming0
  (JNIEnv *, jclass);
JNIEXPORT jlong JNICALL Java_de_uni_1hildesheim_sse_system_android_ThreadDataGatherer_getCpuThreadTime0
  (JNIEnv *, jclass, jlong);
JNIEXPORT void JNICALL Java_de_uni_1hildesheim_sse_system_android_DataGatherer_registerThread0
  (JNIEnv *, jclass, jlong, reg);
#endif

#ifdef __cplusplus
}
#endif
#endif
