/* FingerprintUSBHost - USB Host Fingerprinter library
 * Copyright (c) 2016 Jesse Vincent
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define DEBUG
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
