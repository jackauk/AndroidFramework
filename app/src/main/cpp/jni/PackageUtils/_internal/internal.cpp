#include  <stdlib.h>
#include "internal.h"
#include "../package_utils.h"
#include "logger.h"
#include <vector>
#include <string>
#include <sstream>

#include "string"
#include "android_config.h"

#if USE_NATIVE_SENSOR
    #include "../Orientation/SensorManager.h"
#endif //USE_NATIVE_SENSOR

#if USE_ASSET_READER
    #include "../AssetReader/AssetReader.h"
#endif //USE_ASSET_READER

namespace fw_utils
{
    namespace fw_internal
    {
        jmethodID       Internal::s_getAssetId = 0;
        bool            Internal::s_bInitialized = false;

        void Internal::Init()
        {
            if (!s_bInitialized)
            {
                InitializeCachedVars();
                s_bInitialized = true;
            }
            #if USE_NATIVE_SENSOR
                fw_utils::modules::AndroidSensorManager::AndroidInitSensor();
            #endif //USE_NATIVE_SENSOR

            #if USE_ASSET_READER
                fw_utils::modules::AssetReader::InitAssetManager();
            #endif //USE_ASSET_READER
        }
        void Internal::InitializeCachedVars() {}




    };
};