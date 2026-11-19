#pragma once

// Radio switch library
// FlameCyclone 2025.4.11

#ifdef RADIOSWITCH_EXPORTS
#define RADIOSWITCH_API __declspec(dllexport)
#else
#define RADIOSWITCH_API __declspec(dllimport)
#endif

extern "C"
{
	RADIOSWITCH_API void RadiosInit();
	RADIOSWITCH_API void RadiosUninit();
	RADIOSWITCH_API bool RadiosGetBlueToothState();
	RADIOSWITCH_API bool RadiosSetBlueToothState(bool fEnable);
	RADIOSWITCH_API bool RadiosGetWifiState();
	RADIOSWITCH_API bool RadiosSetWifiState(bool fEnable);
	RADIOSWITCH_API bool RadiosGetFMState();
	RADIOSWITCH_API bool RadiosSetFMState(bool fEnable);
	RADIOSWITCH_API bool RadiosGetMobileBroadbandState();
	RADIOSWITCH_API bool RadiosSetMobileBroadbandState(bool fEnable);
}
