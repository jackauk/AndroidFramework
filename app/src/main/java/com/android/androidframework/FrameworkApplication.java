package com.android.androidframework;

import android.app.Activity;
import android.app.Application;
import android.content.Context;
import android.util.Log;
public class FrameworkApplication extends Application {
    private static Context context;

    //Mutildex
    public void onCreate()
    {
        super.onCreate();
        FrameworkApplication.context = getApplicationContext();
        Log.i("context"," init context");
    }
    public static Context getContext()
    {
        if ( FrameworkApplication.context == null)
        {
            throw new JAException("FrameworkApplication.context == null");
        }
        return FrameworkApplication.context;
    }

    public static Context getContext(Activity activity)
    {
        if ( FrameworkApplication.context == null)
        {
            Log.i("context","getContext(activity) FrameworkApplication.context is null, try to get from activity");
            FrameworkApplication.context = activity.getApplicationContext();

            if ( FrameworkApplication.context == null)
            throw new JAException("getContext(activity ) FrameworkApplication.context == null");
        }
        return FrameworkApplication.context;
    }



    static class JAException extends RuntimeException
    {
        public JAException()
    {
        Log.i("context","JAException()");
    }
        public JAException(String message)
        {
            super(message);
            Log.i("context","JAException() message: "+ message );
        }
        public JAException(Throwable cause)
        {
            super(cause);
            Log.i("context","JAException() cause: "+ cause.toString() );
        }
        public JAException(String message,Throwable cause)
        {
            super(message, cause);
            Log.i("context","JAException() message,cause: "+ cause.toString() );
        }

    }
}

