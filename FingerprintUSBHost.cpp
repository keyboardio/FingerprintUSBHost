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

    if ( setup.bmRequestType != REQUEST_DEVICETOHOST  || setup.bRequest != GET_DESCRIPTOR || setup.wValueH != USB_STRING_DESCRIPTOR_TYPE)  {

      return 0;
    }


    if (setup.wLength == 0xff) {
      maybe_linux++;
      maybe_win++;
      not_mac++; // In testing, MacOS NEVER sets a descript request lenght of 255
    } else {

      not_linux++; // In testing, Linux ALWAYS sets a descriptor request length of 255;
    }

    return 0;
}

void FingerprintUSBHost_::guessHostOS(String &os) {

  if (not_mac > 0 && not_linux > 0 && maybe_win > 0) {
    os="Windows";
  } else if ( maybe_linux > 0 && not_linux == 0 ) {
    os="Linux";
  } else if ( not_mac == 0)  {
    os="MacOS";

  } else {
    os="unsure";
  }
}


bool FingerprintUSBHost_::setup(USBSetup& setup)
{
//    usbSetups[usbSetupCount++] = setup;
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
