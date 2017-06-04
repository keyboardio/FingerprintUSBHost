#include "FingerprintUSBHost.h"

#if defined(USBCON)

FingerprintUSBHost_ FingerprintUSBHost;

int FingerprintUSBHost_::getInterface(uint8_t* interfaceCount) {
    return 0;
}

int FingerprintUSBHost_::getDescriptor(USBSetup& setup) {
    usbSetups[usbSetupCount++] = setup;

    if (setup.bmRequestType != REQUEST_DEVICETOHOST  || setup.bRequest != GET_DESCRIPTOR || setup.wValueH != USB_STRING_DESCRIPTOR_TYPE)  {

        return 0;
    }


    if (setup.wLength == 0xff) {
        guess.maybe_linux = 1;
        guess.maybe_win = 1;
        guess.not_mac = 1; // In testing, MacOS NEVER sets a descript request lenght of 255
    } else {
        guess.not_linux = 1; // In testing, Linux ALWAYS sets a descriptor request length of 255;
    }

    return 0;
}

GuessedHost::OSVariant FingerprintUSBHost_::guessHostOS(void) {

    if (guess.not_mac && guess.not_linux && guess.maybe_win) {
        return GuessedHost::WINDOWS;
    } else if (guess.maybe_linux && !guess.not_linux) {
        return GuessedHost::LINUX;
    } else if (! guess.not_mac)  {
        return GuessedHost::MACOS;

    } else {
        return GuessedHost::UNSURE;
    }
}

void FingerprintUSBHost_::guessHostOS(String &os) {
    switch (guessHostOS()) {
    case GuessedHost::WINDOWS:
        os="Windows";
        break;
    case GuessedHost::LINUX:
        os="Linux";
        break;
    case GuessedHost::MACOS:
        os="MacOS";
        break;
    default:
        os="unsure";
        break;
    }
}


bool FingerprintUSBHost_::setup(USBSetup& setup) {
//    usbSetups[usbSetupCount++] = setup;
    return false;
}

FingerprintUSBHost_::FingerprintUSBHost_(void) : PluggableUSBModule(0, 0, epType) {
    memset(&guess, 0, sizeof(guess));
    PluggableUSB().plug(this);
}

int FingerprintUSBHost_::begin(void) {
    return 0;
}



#endif /* if defined(USBCON) */
