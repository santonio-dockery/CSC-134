// CSC 154
// M1T1 Module 1, tutorial 1

//well explain later
#include <iostream>
#include <cmath>
using namespace std;

int main() {        
    cout << "Hello, World!" << endl;
    cout << endl; //blank line
    cout << "Enter your first name: ";
    string name; // Declare a string variable
    cin >> name; // Get input from the user

    cout << "Hello " + name + " welcome to C++! ";
    cout << endl; //blank line

    // get numeric input and perform some math
    int num1;

    cout << "Enter a whole number: ";
    cin >> num1;

    cout << "Your number is " + to_string(num1); 
    cout << endl; //blank line

    // another way to print integers in a string
    cout << "Your number is " << num1 << endl;

// get the exponent from the user
int exponent;
cout << "Enter an exponent: ";
cin >> exponent;

//creat a new variable to hold the math answer
// num1 to the power of the exponent
int result = pow(num1,exponent);

//output
cout << num1 << " raised to the power of " << exponent << " is " << result << endl;

  return 0; // exit with no errors
}