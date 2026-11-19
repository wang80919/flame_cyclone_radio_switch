#include "pch.h"
#include "RadiosSwitch.h"
#include <Windows.h>
#include <winrt/Windows.Devices.Radios.h>
#include <winrt/Windows.Foundation.Collections.h>
#pragma comment(lib, "windowsapp")

using namespace winrt;
using namespace Windows::Devices::Radios;
using namespace Windows::Foundation::Collections;

RadioState GetRadioState(RadioKind kind);
bool SetRadioState(RadioKind kind, bool fEnable);

RADIOSWITCH_API void RadiosInit()
{
    winrt::init_apartment();
}

RADIOSWITCH_API void RadiosUninit()
{
    winrt::uninit_apartment();
}

RADIOSWITCH_API bool RadiosGetBlueToothState()
{
    return RadioState::On == GetRadioState(RadioKind::Bluetooth);
}

RADIOSWITCH_API bool RadiosSetBlueToothState(bool fEnable)
{
    return SetRadioState(RadioKind::Bluetooth, fEnable);
}

RADIOSWITCH_API bool RadiosGetWifiState()
{
    return RadioState::On == GetRadioState(RadioKind::WiFi);
}

RADIOSWITCH_API bool RadiosSetWifiState(bool fEnable)
{
    return SetRadioState(RadioKind::WiFi, fEnable);
}

RADIOSWITCH_API bool RadiosGetFMState()
{
    return RadioState::On == GetRadioState(RadioKind::FM);
}

RADIOSWITCH_API bool RadiosSetFMState(bool fEnable)
{
    return SetRadioState(RadioKind::FM, fEnable);
}

RADIOSWITCH_API bool RadiosGetMobileBroadbandState()
{
    return RadioState::On == GetRadioState(RadioKind::MobileBroadband);
}

RADIOSWITCH_API bool RadiosSetMobileBroadbandState(bool fEnable)
{
    return SetRadioState(RadioKind::MobileBroadband, fEnable);
}

RadioState GetRadioState(RadioKind kind)
{
    do
    {
        try
        {
            auto radios = Radio::GetRadiosAsync().get();
            for (const auto& radio : radios)
            {
                if (radio.Kind() == kind)
                {
                    return radio.State();
                    break;
                }
            }

        }
        catch (const winrt::hresult_error& e)
        {
            UNREFERENCED_PARAMETER(e);
            break;
        }

    } while (false);

    return RadioState::Unknown;
}

bool SetRadioState(RadioKind kind, bool fEnable)
{
    bool fResult = false;

    do
    {
        try
        {
            auto radios = Radio::GetRadiosAsync().get();
            for (const auto& radio : radios)
            {
                if (radio.Kind() == kind)
                {
                    fResult = true;
                    radio.SetStateAsync(fEnable ? RadioState::On : RadioState::Off).get();
                    break;
                }
            }
        }
        catch (const winrt::hresult_error& e)
        {
            UNREFERENCED_PARAMETER(e);
            break;
        }

    } while (false);

    return fResult;
}
