// M5t1 - more functions
//santoniod
// 3/18/26
//show off different function types





#include <iostream>

using namespace std;

// function declaractions
void say_hi();
int show_answer();
double square_a_number(double number);
//main goes here

int main()
{
    say_hi();
    cout << "The answer is: " << show_answer() << endl;
    cout << "Enter a number: ";
    double number;
    cin >> number;
    double answer = square_a_number(number);
    cout << number << " squared is " << answer << endl;
    return 0;
}

// function defintions (full code))
void say_hi () {
 cout << "Hello world!" << endl;
 return; //optional assumed
}

int show_answer() {
  int answer = 42;
  return answer;
}

double square_a_number(double number) {
double square = number * number ;
return square;
}
