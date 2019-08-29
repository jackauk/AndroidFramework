//
// Created by hien.nguyenmanh on 8/28/2019.
//

#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativec_MainActivity_stringFromJNImain(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++. Its first times from _main_.cpp";
    return env->NewStringUTF(hello.c_str());
}
