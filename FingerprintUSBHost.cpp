#include "FingerprintUSBHost.h"

#if defined(USBCON)

FingerprintUSBHost_ FingerprintUSBHost;

int FingerprintUSBHost_::getInterface(uint8_t* interfaceCount)
{
    return 0;
}

int FingerprintUSBHost_::getDescriptor(USBSetup& setup)
{
    usbSetups[usbSetupCount++] = setup;
    return 0;
}

bool FingerprintUSBHost_::setup(USBSetup& setup)
{
    usbSetups[usbSetupCount++] = setup;
    return false;
}

FingerprintUSBHost_::FingerprintUSBHost_(void) : PluggableUSBModule(0, 0, epType)
{
    PluggableUSB().plug(this);
}

int FingerprintUSBHost_::begin(void)
{
    return 0;
}



#endif /* if defined(USBCON) */
