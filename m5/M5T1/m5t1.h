#ifndef M5T1_H_INCLUDED
#define M5T1_H_INCLUDED

#include <iostream>

using namespace std;



// function defintions (full code))
void say_hi () {
 cout << "Hello world!" << endl;
 return; //optional assumed
}

int show_answer() {
  int answer = 42;
  return answer; // return is required becauses its not void
}

double square_a_number(double number) {
double square = number * number ;
return square;
}


#endif // M5T1_H_INCLUDED
