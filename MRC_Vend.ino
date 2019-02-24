#include <PinChangeInterruptSettings.h>
#include <PinChangeInterrupt.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterruptPins.h>

// Array to determine which relay to activate
bool deliver[16] = {false,false,false,false,false,false,false,false,
            false,false,false,false,false,false,false,false};
// Transkate analog pins
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15};

// BUTTON PINS
//Arduino Mega: 10, 11, 12, 13, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64),
//               A11 (65), A12 (66), A13 (67), A14 (68), A15 (69)

// OUTPUT PINS
// 0-7, A0 - A7

// Functions that attach to interrupts
void flip0(){deliver[0] = true;}
void flip1(){deliver[1] = true;}
void flip2(){deliver[2] = true;}
void flip3(){deliver[3] = true;}
void flip4(){deliver[4] = true;}
void flip5(){deliver[5] = true;}
void flip6(){deliver[6] = true;}
void flip7(){deliver[7] = true;}
void flip8(){deliver[8] = true;}
void flip9(){deliver[9] = true;}
void flip10(){deliver[10] = true;}
void flip11(){deliver[11] = true;}
void flip12(){deliver[12] = true;}
void flip13(){deliver[13] = true;}
void flip14(){deliver[14] = true;}
void flip15(){deliver[15] = true;}

void setup() {
  // put your setup code here, to run once:
  // All the pinmode config ever
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  pinMode(51, INPUT_PULLUP);
  pinMode(52, INPUT_PULLUP);
  pinMode(53, INPUT_PULLUP);
  pinMode(A8, INPUT_PULLUP);
  pinMode(A9, INPUT_PULLUP);
  pinMode(A10, INPUT_PULLUP);
  pinMode(A11, INPUT_PULLUP);
  pinMode(A12, INPUT_PULLUP);
  pinMode(A13, INPUT_PULLUP);
  pinMode(A14, INPUT_PULLUP);
  pinMode(A15, INPUT_PULLUP);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  attachPCINT(digitalPinToPCINT(10), flip0, FALLING);
  attachPCINT(digitalPinToPCINT(11), flip1, FALLING);
  attachPCINT(digitalPinToPCINT(12), flip2, FALLING);
  attachPCINT(digitalPinToPCINT(13), flip3, FALLING);
  attachPCINT(digitalPinToPCINT(50), flip4, FALLING);
  attachPCINT(digitalPinToPCINT(51), flip5, FALLING);
  attachPCINT(digitalPinToPCINT(52), flip6, FALLING);
  attachPCINT(digitalPinToPCINT(53), flip7, FALLING);
  attachPCINT(digitalPinToPCINT(A8), flip8, FALLING);
  attachPCINT(digitalPinToPCINT(A9), flip9, FALLING);
  attachPCINT(digitalPinToPCINT(A10), flip10, FALLING);
  attachPCINT(digitalPinToPCINT(A11), flip11, FALLING);
  attachPCINT(digitalPinToPCINT(A12), flip12, FALLING);
  attachPCINT(digitalPinToPCINT(A13), flip13, FALLING);
  attachPCINT(digitalPinToPCINT(A14), flip14, FALLING);
  attachPCINT(digitalPinToPCINT(A15), flip15, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 8; i++){
    if (deliver[i]){
      digitalWrite(i, HIGH);
      delay(1500);
      digitalWrite(i, LOW);
      deliver[i] = false;
    }
  }
  for(int i = 8; i < 16; i++){
    if (deliver[i]){
      digitalWrite(analog_pins[i-8], HIGH);
      delay(1500);
      digitalWrite(analog_pins[i-8], LOW);
      deliver[i] = false;
    }
  }
}
