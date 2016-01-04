#pragma once

#include <stdint.h>
#include <Arduino.h>
#include "PluggableUSB.h"


class FingerprintUSBHost_ : public PluggableUSBModule
{
public:
  FingerprintUSBHost_(void);
  int begin(void);
  void guessHostOS(String &os);
    //  USBSetup usbSetups[64];
    // int usbSetupCount = 0;

protected:
  // Implementation of the PluggableUSBModule
  int getInterface(uint8_t* interfaceCount);
  int getDescriptor(USBSetup& setup);
  bool setup(USBSetup& setup);


private:
  uint8_t epType[0];
  uint8_t maybe_linux = 0;
  uint8_t maybe_win = 0;
  uint8_t maybe_mac = 0;
  uint8_t not_linux = 0;
  uint8_t not_win = 0;
  uint8_t not_mac = 0;



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
