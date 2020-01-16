#include    "AssetReader.h"

#include "../package_utils.h"
#include "../_internal/logger.h"

#include <jni.h>
#include <android/asset_manager_jni.h>

namespace fw_utils
{
    namespace modules
    {
        AAssetManager* AssetReader::assetManager = NULL;
        jobject AssetReader::javaAssetManagerRef = NULL;
        void AssetReader::InitAssetManager() {

        }
    };
};