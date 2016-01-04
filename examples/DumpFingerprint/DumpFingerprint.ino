#include "FingerprintUSBHost.h"
#include "Keyboard.h"
#include "Mouse.h"


// This example depends on a large data structure that's commented out in the codebase
void setup() {
  // put your setup code here, to run once:
    FingerprintUSBHost.begin();
  delay(500);
  int total = FingerprintUSBHost.usbSetupCount;

  Keyboard.begin();
  Mouse.begin();
  for(int i = 0 ;i<total;i++) {
    Keyboard.print(FingerprintUSBHost.usbSetups[i].bmRequestType,HEX);

    Keyboard.print(" ");
    Keyboard.print(FingerprintUSBHost.usbSetups[i].bRequest,HEX);
    Keyboard.print(" ");
    
    Keyboard.print(FingerprintUSBHost.usbSetups[i].wValueL,HEX);
    Keyboard.print(" ");
    Keyboard.print(FingerprintUSBHost.usbSetups[i].wValueH,HEX);
    Keyboard.print(" ");
    Keyboard.print(FingerprintUSBHost.usbSetups[i].wIndex,HEX);
    Keyboard.print(" ");
    Keyboard.print(FingerprintUSBHost.usbSetups[i].wLength,HEX);

    Keyboard.print(" ");
    Keyboard.print("\n");
  

   }
}

void loop() {
  // put your main code here, to run repeatedly:

}