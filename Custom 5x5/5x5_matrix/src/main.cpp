#include <Arduino.h>

//* ACTIVE LOW

const int rows = 5;
const int cols = 5;

const int row_pins[rows] = {2, 3, 4, 5, 6};
const int col_pins[cols] = {22, 24, 26, 28, 30};

// settings
const double delay_between_chars = 800;

// function prototypes
void power_on_test();
void sequence_processor(int arr[][cols]);
void draw_character(int arr[][cols]);
void draw_word(String str);
// void switch_row(int *row, int state);
// void switch_col(int col, int state);


// SEQUENCES -> LETTERS
int A[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0}
};

int B[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int C[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 1, 1, 1, 1},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0}
};


int D[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int E[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0}
};

int F[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 1, 1, 1, 1}
};

int G[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int H[5][5] = {
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0}
};

int I[5][5] = {
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1}
};

int J[5][5] = {
  {0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {0, 0, 0, 1, 1}
};

int K[5][5] = {
  {0, 1, 1, 0, 1},
  {0, 1, 0, 1, 1},
  {0, 0, 1, 1, 1},
  {0, 1, 0, 1, 1},
  {0, 1, 1, 0, 1}
};

int L[5][5] = {
  {0, 1, 1, 1, 1},
  {0, 1, 1, 1, 1},
  {0, 1, 1, 1, 1},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0}
};

int M[5][5] = {
  {0, 1, 1, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0}
};

int N[5][5] = {
  {0, 1, 1, 1, 0},
  {0, 0, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 0, 0},
  {0, 1, 1, 1, 0}
};

int O[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

int P[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 1, 1, 1, 1}
};

int Q[5][5] = {
  {0, 0, 0, 0, 1},
  {0, 1, 1, 0, 1},
  {0, 1, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

int R[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 0, 1},
  {0, 1, 1, 1, 0}
};

int S[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int T[5][5] = {
  {0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1}
};

int U[5][5] = {
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int V[5][5] = {
  {1, 1, 1, 1, 1},
  {0, 1, 1, 1, 0},
  {1, 0, 1, 0, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 1, 1, 1}
};

int W[5][5] = {
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0}
};

int X[5][5] = {
  {0, 1, 1, 1, 0},
  {1, 0, 1, 0, 1},
  {1, 1, 0, 1, 1},
  {1, 0, 1, 0, 1},
  {0, 1, 1, 1, 0}
};

int Y[5][5] = {
  {0, 1, 1, 1, 0},
  {1, 0, 1, 0, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1}
};

int Z[5][5] = {
  {0, 0, 0, 0, 0},
  {1, 1, 1, 0, 1},
  {1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1},
  {0, 0, 0, 0, 0}
};

int N1[5][5] = {
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

int N2[5][5] = {
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0}
};

int N3[5][5] = {
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int N4[5][5] = {
  {0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0}
};

int N5[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int N6[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int N7[5][5] = {
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0}
};

int N8[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

int N9[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0}
};


// map<char,arr[][cols]> alphabet{
//   {'A',A}
// };

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


  draw_word("LENNY");
  // sequence_processor(A);
  draw_character(L);
  delay(delay_between_chars);
  draw_character(E);
  delay(delay_between_chars);
  draw_character(N);
  delay(delay_between_chars);
  draw_character(N);
  delay(delay_between_chars);
  draw_character(Y);
  delay(delay_between_chars);

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

// ACTIVE HIGH
// {
// {1,1,1,1,1}
// {1,0,0,0,1}
// {1,1,1,1,1}
// {1,0,0,0,1}
// {1,0,0,0,1}
// }


// ACTIVE LOW
// {
// {0,0,0,0,0}
// {0,1,1,1,0}
// {0,0,0,0,0}
// {0,1,1,1,0}
// {0,1,1,1,0}
// };


void draw_word(String str){
  int str_length = str.length();


  // Serial.print(str);
  // Serial.print(" - ");
  // Serial.println(str_length);

  char string_array[str_length] = {};
  for(int i=0; i<str_length; i++){
    string_array[i] = str[i];
    Serial.print(string_array[i]);
    Serial.print('.');
  }
  Serial.println();

}

void draw_character(int arr[][cols]){
  for(int itertions=0; itertions<40; itertions++){
    sequence_processor(arr);
  }
  
}

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