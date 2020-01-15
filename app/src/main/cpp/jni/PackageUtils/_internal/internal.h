#ifndef __FW_INTERNAL_H__
#define __FW_INTERNAL_H__

#include <android/native_window.h> // requires ndk r5 or newer
#include <jni.h>

#include "../helpers.h"


namespace fw_utils
{
    namespace fw_internal
    {
        class Internal
        {
        private:

            // Initialize only at beginning, initializes variables that are cached in the native
            static void InitializeCachedVars();

            //Refresh cached vars
            static void RefreshCachedVars();

            //Clean
            static void CleanCachedVars();
        public:
            static void Init();

            static void LoadClasses( JNIEnv*):

            //Setter method
            static void SetVM(JavaVM*);
            static void SetWindow( ANativeWindow*, int, int);

            static void SetConnection(const fw_utils::helpers::)




        }



    }
}



#endif //__FW_INTERNAL_H__