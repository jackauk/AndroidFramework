


const char* jclass_OS[] = 
{
	"java/lang/Class", 
	"android/os/Build",
	"android/content/Intent",
	"android/os/Bundle",
	"android/media/AudioTrack",
	"java/security/SecureRandom",
	"java/util/HashSet",
	"java/lang/Long",
	"java/security/spec/X509EncodedKeySpec",
	"java/security/KeyFactory",
	"java/security/NoSuchAlgorithmException",
	"java/security/spec/InvalidKeySpecException",
	"com/gameloft/glotv3/PortingJNIv3",
	"com/gameloft/ingamebrowser/InGameBrowser",	
	//av todo:  SplashScrenActivity should be via #if USE_WELCOME_SCREEN/ CRM
	"com/gameloft/ingamebrowser/SplashScreenActivity",
#if USE_POPUPSLIB
	"com/gameloft/popupslib/PopUpsBridgeClass",
#endif
	"com/gameloft/gameoptions/DeviceOptions",
	"com/gameloft/GLSocialLib/PlatformAndroid",
	"com/gameloft/GLSocialLib/facebook/FacebookAndroidGLSocialLib",
#if HUAWEI_STORE
	"com/gameloft/GLSocialLib/Huawei/HuaweiAndroidGLSocialLib",//Nhut add hw
#endif
#if USE_GLSOCIALLIB_SNS_XBOX
#if !defined(__X86_64__) //khai rem, x86_64 xbox live sdk is not available
	"com/gameloft/GLSocialLib/xboxlive/XboxLiveAndroidGLSocialLib",
#endif
#endif
#if AMAZON_STORE
	"com/gameloft/GLSocialLib/gamecircle/GameCircleAndroidGLSocialLib",
#else //GameApi
	"com/gameloft/GLSocialLib/GameAPI/GameAPIAndroidGLSocialLib",
#endif //AMAZON_STORE
	"com/gameloft/adsmanager/FAN",
	"com/gameloft/adsmanager/Vungle",
	"com/gameloft/adsmanager/AdMob",
	"com/gameloft/adsmanager/IronSource",
	"com/gameloft/adsmanager/UnityAds",
	"com/gameloft/adsmanager/AppLovin",
	"com/gameloft/adsmanager/BaseAdsProvider",
	"com/gameloft/adsmanager/Banner/BaseBannerObject",
	"com/gameloft/adsmanager/Incentivized/BaseIncentivizedObject",
	"com/gameloft/adsmanager/Interstitial/BaseInterstitialObject",
	"com/gameloft/adsmanager/Native/BaseNativeObject",
	"com/gameloft/adsmanager/OfferWall/BaseOfferWallObject",
	"com/gameloft/glads/AndroidDevice",
	"com/gameloft/glads/AndroidWebView",
	"com/gameloft/glads/AndroidAds",
	"com/gameloft/glads/MRAIDHtmlProcessor",
	"com/gameloft/glads/MoatSDK",
	"com/gameloft/glads/AvidSDK",
	"com/gameloft/glads/OmSDK",
	"com/gameloft/olplatform/OLPJNIUtils"
};

const char* jclass_const[] = 
{
	"/PackageUtils/AndroidUtils",
	"/PackageUtils/EmulatorDetector",
	"/PackageUtils/LogoViewPlugin",
	"/DataSharing",
	"/SignatureChecker",
	"/GLUtils/controller/NativeBridgeHIDControllers",
	"/GLUtils/controller/NativeBridgeKeyboard",
	"/GLUtils/Device",
	"/GLUtils/SUtils",
	"/GLUtils/CutoutHelper",
	"/iab/InAppBilling",
	"/iab/common/Base64",
	"/iab/common/Base64DecoderException",
	"/PushNotification/SimplifiedAndroidUtils",
	"/SendInfo",
	//av todo:  SplashScrenActivity should be via #if USE_WELCOME_SCREEN/ CRM
	"/SplashScreenActivity",
	"/AppDetection",
	"/PackageUtils/ClipboardPlugin",
#if USE_ADS_SERVER
	"/PackageUtils/AdServerPlugin",
#endif 
#if USE_BILLING
	"/billing/AndroidBilling",
#endif	
	
#if (TARGET_API_LEVEL_INT >= 23)
	"/PackageUtils/PermissionPlugin",
#endif

#if (ENABLE_GOOGLE_INVITES)
	"/PackageUtils/GoogleInvitePlugin",
#endif

#if (ENABLE_PLAY_GAMES_API)
	"/PackageUtils/GooglePlay/GooglePlayGames",
	"/PackageUtils/GooglePlay/GPProfile",
	"/PackageUtils/GooglePlay/GPAchievements",
	"/PackageUtils/GooglePlay/GPLeaderboards",
	"/PackageUtils/GooglePlay/GPPlusOne",
#endif

#if GLOFT_DRM
	"/DRM/Gloft/GloftDrmImpl",
#endif //GLOFT_DRM

#if ENABLE_WIFI_SCANNER
	"/PackageUtils/WifiInfoPlugin",
#endif
#if (USE_IGP_FREEMIUM)
	//Deprecated "/PackageUtils/InGamePromotionPlugin",
#endif	

#if USE_CRASHLYTICS
	"/GLUtils/CrashlyticsUtils",
#endif

#if ADD_GOOGLE_FIREBASE_SERVICES
	"/GoogleFirebase/GoogleFirebase",
#endif

#if !RELEASE_VERSION
	"/presets/PresetLoader",
#endif

#if USE_HPK
  "/PackageUtils/HpkUtils",
#endif

};

