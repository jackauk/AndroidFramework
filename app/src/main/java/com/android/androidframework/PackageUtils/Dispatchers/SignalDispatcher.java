package com.android.androidframework.PackageUtils.Dispatchers;

import android.content.Intent;
import android.app.Activity;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.ViewGroup;

import com.android.androidframework.PackageUtils.PluginSystem.PluginEventDispatcher;

public class SignalDispatcher {
    private PluginEventDispatcher m_pPluginEventDispatcher;
    public SignalDispatcher()
    {
        m_pPluginEventDispatcher =new PluginEventDispatcher();
    }
}
