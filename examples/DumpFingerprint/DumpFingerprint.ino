#include "FingerprintUSBHost.h"
#include "Keyboard.h"

void setup() {

    delay(4000);
    Keyboard.begin();

    String os;
    FingerprintUSBHost.guessHostOS(os);
    Keyboard.print("I think the host OS is ");
    Keyboard.print(os);
    Keyboard.println(".");

    Keyboard.print(".\n\n");

    Keyboard.print("If I'm wrong Please submit a GitHub issue with the following data at:\n");
    Keyboard.print("https://github.com/keyboardio/FingerprintUSBHost/issues\n");
    Keyboard.print("Be sure to include your OS and OS version.\n\n");

    int total = FingerprintUSBHost.usbSetupCount;

    for (int i = 0 ; i < FingerprintUSBHost.usbSetupCount; i++) {

        USBSetup s = FingerprintUSBHost.usbSetups[i];

        Keyboard.print(s.bmRequestType, HEX);
        Keyboard.print(",");

        Keyboard.print(s.bRequest, HEX);
        Keyboard.print(",");
        Keyboard.print(s.wValueH, HEX);
        Keyboard.print(",");
        Keyboard.print(s.wValueL, HEX);
        Keyboard.print(",");

        Keyboard.print(s.wIndex, HEX);
        Keyboard.print(",");
        Keyboard.print(s.wLength, HEX);

        Keyboard.print("\n");
        delay(10);

    }
}

void loop() {
    // put your main code here, to run repeatedly:

}

