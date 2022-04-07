#include <Arduino.h>

//* ACTIVE LOW

const int rows = 5;
const int cols = 5;

const int row_pins[rows] = {2, 3, 4, 5, 6};
const int col_pins[cols] = {22, 24, 26, 28, 30};

// function prototypes
void power_on_test();
void sequence_processor(int arr[][cols]);
// void switch_row(int *row, int state);
// void switch_col(int col, int state);

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i = 0; i < rows; i++)
  {
    pinMode(row_pins[i], OUTPUT);
  }

  for (int j = 0; j < cols; j++)
  {
    pinMode(col_pins[j], OUTPUT);
  }

  power_on_test();
}

void loop()
{

  int sequence[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 1, 1, 0}
  };

  sequence_processor(sequence);

  // put your main code here, to run repeatedly:
  // switch_row(0,1);
  // switch_col(0,0);
  // delay(500);
  // switch_row(0,0);
  // switch_col(0,1);
  // delay(500);
}

void power_on_test()
{

  //* Turn each LED on one at a time.
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      digitalWrite(row_pins[row], HIGH);
      // switch_row(&row,1);
      digitalWrite(col_pins[col], LOW);
      delay(200);
      digitalWrite(row_pins[row], LOW);
      digitalWrite(col_pins[col], HIGH);
    }
  }

  delay(500);

  //* All LEDs Flash
  //! not all at once
  // for (int i = 0; i < 3; i++)
  // {
  //   for (int row = 0; row < rows; row++)
  //   {
  //     for (int col = 0; col < cols; col++)
  //     {
  //       digitalWrite(row_pins[row], HIGH);
  //       digitalWrite(col_pins[col], LOW);
  //     }
  //   }
  //   delay(300);
  //   for (int row = 0; row < rows; row++)
  //   {
  //     for (int col = 0; col < cols; col++)
  //     {
  //       digitalWrite(row_pins[row], LOW);
  //       digitalWrite(col_pins[col], HIGH);
  //     }
  //   }
  //   delay(300);
  // }
}

// {
// {1,1,1,1,1}
// {1,0,0,0,1}
// {1,1,1,1,1}
// {1,0,0,0,1}
// {1,0,0,0,1}
// }


void sequence_processor(int arr[][cols]){

  // contraint: input_array must be square matrix
  for (int i=0; i<rows; i++){
    // Turn the ROW HIGH
    digitalWrite(row_pins[i], HIGH);
    // select a particular col using i (thus the square matrix constraint.)
    // loop through the col (array) and change LED state.
    // loop through the col_pins (array) and change LED state.

    //! ERROR: 
    // int selected_col[cols] = arr[i];

    //? FIX
    int selected_col[cols] = {};
    for(int j=0; j<cols; j++){
      selected_col[j] = arr[i][j];
    }

    for(int k=0; k<cols; k++){
      
        digitalWrite(col_pins[k], selected_col[k]);
    }
    delay(2);

    // Turn the ROW LOW
    digitalWrite(row_pins[i], LOW);
    // delay(1);

  }
}