#ifndef _FW_ASSET_READER
#define _FW_ASSET_READER

#include <stdio.h>
#include <jni.h>
#include <android/asset_manager.h>

// Wrapper function for Android assets

namespace fw_utils
{
    namespace modules
    {
        //AssetReader provides access to the application's raw assets
        // AssetReader is a wrapper over the android NDK's AAssetManger

        // important notes:
        //  AAsset
        //      - provides access to a read-only asset.
        //      - object are NOT thread-safe, and should not be shared across threads
        //  AAssetDir
        //      - provides  access to a chunk if the asset hierarchy as if it was a single directory
        //      - the list of files will be sorted in ascending order by ASCII value
        class AssetReader
        {
        // Manager pointer that maybe shared across multiple threads
            static AAssetManager* assetManager;
        public:
            static jobject javaAssetManagerRef;

            enum AccessMode
            {
                MODE_UNKNOWN = 0, //No specification information about how data will be accessed
                MODE_RANDOM,      //Read chunk. and seek forward and backward
                MODE_STREAMIN,    //Read sequentially, with an occasional forward seek
                MODE_BUFFER         // Caller plans to ask for a read-only buffer with all data
            };

            //Open a asset
            //@param [in] filename - name of asset
            //@param [in] mode - access mode to use when opening
            //return  AAsset object
            static AAsset* open( const char* filename, AccessMode mode);

            //read ''
            static void InitAssetManager();
        };

    }


};

#endif //_FW_ASSET_READER