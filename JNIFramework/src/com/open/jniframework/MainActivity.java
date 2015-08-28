package com.open.jniframework;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
    
    private JNITest mJNITest;
    private Button mButton1 = null;
    private Button mButton2 = null;
    private Button mButton3 = null;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mJNITest = new JNITest();
    }
    
    @Override
    public void onResume() {
        super.onResume();
        
        Log.i("JNIFramework", "call onResume");
        mButton1 = (Button) findViewById(R.id.button1);
        mButton1.setClickable(true);
        mButton1.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.i("JNIFramework", "call native JNITest1");
                boolean result = mJNITest.JNITest1("Hello", "World");
                Toast.makeText(MainActivity.this, result ? "Success" : "Failed", Toast.LENGTH_LONG).show();
            }
        });
        
        mButton2 = (Button) findViewById(R.id.button2);
        mButton2.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.i("JNIFramework", "call native JNITest2");
                boolean result = mJNITest.JNITest2();
                Toast.makeText(MainActivity.this, result ? "Success" : "Failed", Toast.LENGTH_LONG).show();
            }
        });
        
        mButton3 = (Button) findViewById(R.id.button3);
        mButton3.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.i("JNIFramework", "call native JNITest3");
                byte[] result = mJNITest.JNITest3(new String[]{"call", "JNITest3"}, new String("Test3").getBytes());
                if (result != null && result.length > 0) {
                    String reslutValue = new String(result);
                    Log.i("JNIFramework", "result = " + reslutValue);
                }
            }
        });
    }
    
}
