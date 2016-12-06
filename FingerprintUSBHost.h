#pragma once

#include <stdint.h>
#include <Arduino.h>
#include "PluggableUSB.h"

namespace GuessedHost {
typedef enum {
    UNSURE,
    LINUX,
    WINDOWS,
    MACOS,
} OSVariant;
};

class FingerprintUSBHost_ : public PluggableUSBModule {
  public:
    FingerprintUSBHost_(void);
    int begin(void);
    GuessedHost::OSVariant guessHostOS(void);
    void guessHostOS(String &os);
    USBSetup usbSetups[32];
    int usbSetupCount = 0;

  protected:
    // Implementation of the PluggableUSBModule
    int getInterface(uint8_t* interfaceCount);
    int getDescriptor(USBSetup& setup);
    bool setup(USBSetup& setup);


  private:
    uint8_t epType[0];
    struct {
        uint8_t maybe_linux:1;
        uint8_t maybe_win:1;
        uint8_t maybe_mac:1;
        uint8_t not_linux:1;
        uint8_t not_win:1;
        uint8_t not_mac:1;
    } guess;


};

/*
 typedef struct
 {
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint8_t wValueL;
    uint8_t wValueH;
    uint16_t wIndex;
    uint16_t wLength;
 } USBSetup;
*/

extern FingerprintUSBHost_ FingerprintUSBHost;
