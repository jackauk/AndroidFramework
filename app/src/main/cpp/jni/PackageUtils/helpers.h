#ifndef FW_HELPERS_H
#define FW_HELPERS_H

#include <string>
#include <vector>
#include <map>

namespace fw_utils
{
	namespace helpers
	{
		enum AccountType
		{
			eAnon = 0,
			eFacebook,
			eGoogle,
		};

		enum Language
		{
			eEnglish = 0,
			//eFrench,
			//eDeutch,
			//eItalian,
			//eSpanish,
			//eJapan,
			//eKorean,
			//eSimplifiedChinese,
			//ePortugeuese_Brazil,
			//eRussian,
			//eTurkish,
			//eArabic,
			//eThai,
			//eIndonesian,
			//eVietnamese,
			//eTraditionalChinese
			eVietnamese
		};

		enum ConnectionType
		{
			eNoConnectivity = 0,	//0
			eConnectivityWifi,		//1
			eConnectivityBlueTooth,	//2
			eConnectivityDummy,		//3
			eConnectivityEthernet,	//4
			eConnectivityWimax,		//5
			eConnectivity2g,		//6
			eConnectivity3g,		//7
			eConnectivity4g,		//8
			eConnectivityUnknown,	//9
		};

		enum EWifiScannerStatus
		{
			eWifiScannerUninitialized = -1,		//-1
			eWifiScannerEnabled = 0,			//0
			eWifiScannerEnabledNoPermission,	//1
			eWifiScannerServiceDisabled,		//2
			eWifiScannerError,					//3
			eWifiScannerDisabled,				//4
		};

		struct WifiScannerResult
		{
			EWifiScannerStatus	status;
			std::string		scanResult;
		};

		enum EUserLocationStatus
		{
			eLocationUninitialized 	= -1,		//-1
			eLocationEnabled		= 0,		//0
			eLocationDisabled,					//1
			eLocationError,						//2
			eLocationPermDisabled,				//3
		};

		/*enum LaunchType
		{
			eUndefined = -1,
			eNormalLaunch = 0,
			eLocalNotif,
			eOnlineNotif,
			eLinkLaunch,
			eAppShortcut,
		};
         */
		struct UserLocation
		{
			EUserLocationStatus		status;
			double					latitude;
			double					longitude;
			float					accuracy;
			std::string				time;
		};
		/*
		struct BHSettings
		{
			BHSettings() : keywords(""), numberOfResults(0), days(0) {}
			std::string				keywords;
			int						numberOfResults;
			int						days;
		};
		*/

		enum NotificationTransportType
		{
			TRANS_UNKOWN = -1,
			TRANS_NONE = 0,
			TRANS_ADM,
			TRANS_FCM,
		};
		/*
		enum GAIDStatus
		{
			eNotAvailable = -2,			//-2
			eUninitialized = -1,		//-1
			eSuccessful	= 0,			//0
			eUserDisabled,				//1
			eGPSUnavailable,			//2
			eNotFinishedLoading,		//3
			eGPSAvailableWithError,		//4
		};
        */
		enum Permission
		{
			eStorage = 0,
			eLocation,
			eContacts,
			ePhone,
			eSMS,
			eMicrophone,
			eCamera
		};

		struct LocalPn
		{
			std::map<std::string, std::string>	pn_data;
			time_t								pn_schedule;
			int									pn_group;
		};

		struct SystemPath
		{
			std::string		sSdCard; //SdCard path. Shouldn't really be used by any game
			std::string 	sAPK;
			std::string		sObb;    //Obb path: Used to get the application path to the obb folder. Android/obb
			std::string		sData;   //Data path: Used to get the application path to the Data folder. Android/data
			std::string		sSave;   //Save path: Used to get the private application path. Android/data/data
			std::string		sTemp;   //Cache path: Used to get the cache dir of your own app
			std::string		sNative; //Native Library path: Used o get the .so dir of your own app
		};

		struct SharedPreferenceContainer //or whatever name you might find more suited for this, mine sucks :)
		{
			std::string 	key;
			std::string 	pName;
		};

		struct HardwareIdentifiers
		{
			std::string 	sAndroidId;
			std::string		sSerial;
            std::string     sCpuSerial;
            std::string     sDeviceManufacturer;
            std::string     sDeviceModel;
			std::string     sBuildProduct;
			std::string     sBuildDevice;
			std::string		sFirmware;
			int				sAPILevel;
			std::string		sWiFiMacAddress;
			std::string		sEthernetMacAddress;
			std::string		sImei;
			std::string		sHdidfv;
			std::vector<std::string> sCpuAbis;
		};

		struct SoftwareIdentifiers
		{
            std::string     sCarrierName;
            std::string     sCountry;
			std::string		sSimCountry;
			std::string		sSettingsCountry;
            std::string     sDeviceLanguage;
			std::string 	sWebviewUserAgent;
			std::string		sApkPath;
			std::vector<std::string>	sApkPaths;
		};

		struct DisplayInfo
		{
			float			xDpi;
			float			yDpi;
			int				nWidth;
			int				nHeight;
		};

		struct GameSpecificIdentifiers
		{
			std::string		sDefaultIgp;
			std::string		sInjectedIgp;
			std::string		sInjectedSerialKey;
			std::string		sGameName;
		};

        struct BatteryInfo
        {
            bool            sIsCharging;
            bool            sUsbCharge;
            bool            sACCharge;
            int             sBatteryStatus; ///< int between 0 and 100
        };
	};
};



#endif // FW_HELPERS_H