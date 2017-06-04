#include "FingerprintUSBHost.h"
#include "Keyboard.h"

void setup() {

    Keyboard.begin();
    String os;
    delay(500); // Take a moment to let things settle

    FingerprintUSBHost.guessHostOS(os);
    Keyboard.print("I think the Host OS is ");
    Keyboard.print(os);
    Keyboard.println();

}
void loop() {
    // put your main code here, to run repeatedly:

}

