package com.open.jniframework;

import android.util.Log;

public class JNITest {

    static {
        try {
        System.loadLibrary("jniFramework");
        } catch (Throwable t) {
            Log.e("JNIFramework", "libjniFramework.so load error:" + t.toString());
        }
    }
    
    /**
     * This function is only called by native C layer through JNI
     */
    public static byte[] javaFunctionTest1(String str, byte[] data) {
        Log.i("JNIFramework", "javaFunctionTest1(): str=" + str + "; data =" + new String(data));
        String value = "call javaFunctionTest1 success!";
        return value.getBytes();
    }

    /***
     * Native methods
     */
    public native boolean JNITest1(String str1, String str2);
    public native boolean JNITest2();
    public native byte[] JNITest3(String[] files, byte[] data);
}
