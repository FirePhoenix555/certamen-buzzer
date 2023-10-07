#include <Keyboard.h>

bool buttonState; // is button pressed

void setup() {
  pinMode(13, OUTPUT); // light turns on when button pressed
  pinMode(2, INPUT_PULLUP); // the button

  Keyboard.begin();

  buttonState = false;
}

void loop() {
  if (!digitalRead(2)) { // button pressed
    digitalWrite(13, HIGH); // display light

    if (!buttonState) { // pressed for first time
      buttonState = true;
      Serial.print("Buzz!\n");

      // input the keyboard commands
      Keyboard.press('b');
      Keyboard.release('b');
      // delay(100);
      Keyboard.press(176); // enter
      Keyboard.release(176);
    }
  } else {
    digitalWrite(13, LOW); // turn light off
    buttonState = false;
  }

  delay(10); // delay for accurate button readings
}
