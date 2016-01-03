#pragma once

#include <stdint.h>
#include <Arduino.h>
#include "PluggableUSB.h"


class FingerprintUSBHost_ : public PluggableUSBModule
{
public:
  FingerprintUSBHost_(void);
  int begin(void);
  USBSetup usbSetups[64];
  int usbSetupCount = 0;

protected:
  // Implementation of the PluggableUSBModule
  int getInterface(uint8_t* interfaceCount);
  int getDescriptor(USBSetup& setup);
  bool setup(USBSetup& setup);


private:
  uint8_t epType[0];

};

// Replacement for global singleton.
// This function prevents static-initialization-order-fiasco
// https://isocpp.org/wiki/faq/ctors#static-init-order-on-first-use
extern FingerprintUSBHost_ FingerprintUSBHost;
