// main.cpp
// M5T2 - More Practice with Functions
// Lists numbers 1-10 and their squares using functions

#include <iostream>
#include "m5t2.h"

using namespace std;

int main() {
    int count;
    int result;

    for (count = 1; count <= 10; count++) {
        result = square(count);
        printAnswerLine(count, result);
    }

    return 0;
}

// Given a number, return the square of it (value-returning)
int square(int number) {
    int result;
    result = number * number;
    return result;
}

// Given two numbers, print them out nicely on one line (void)
void printAnswerLine(int number, int result) {
    cout << number << "\t" << result << endl;
}