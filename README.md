# Android-JNIFramework
This project provide a common JNI framework for Android development.


How to use ?

1. Take reference to com.open.jniframework.JNITest.java, define your native java function.

2. Take reference to jni/test_src/test.c, implement the registerTestMethods() and unregisterTestMethods().

3. Take reference to jni/test_src/JNIGlobalInit.c, call registerTestMethods() in JNI_OnLoad() and call unregisterTestMethods() in JNI_OnUnload().  

4. Change Android.mk to add the files you want to build.

5. Now everything is ok, go to the root directory of Android.mk, execute "ndk-build clean" and "ndk-build" command.

6. When the building finished, you can test your APK.



The main purpose of this project is to show you:

1. How to register/unregister "Java native function" in C/C++ layer.

2. How to deal with the data type between Java and C/C++. Be careful, don't make memory leak.
