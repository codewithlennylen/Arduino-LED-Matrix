#include <Arduino.h>

const int rows = 5;
const int cols = 5;

const int row_pins[rows] = {2,3,4,5,6};
const int col_pins[cols] = {22,24,26,28,30};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<rows; i++){
    pinMode(row_pins[i], OUTPUT);
  }

 for(int j=0; j<cols; j++){
    pinMode(col_pins[j], OUTPUT);
  }

  for(int row=0;row<rows;row++){
    for(int col=0; col<cols; col++){
      digitalWrite(row_pins[row], LOW);
      digitalWrite(col_pins[col], LOW);
    }
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int row=0;row<rows;row++){
    for(int col=0; col<cols; col++){
      digitalWrite(row_pins[row], HIGH);
      digitalWrite(col_pins[col], LOW);
      delay(1000);
      digitalWrite(row_pins[row], LOW);
      digitalWrite(col_pins[col], HIGH);
    }
  }
}