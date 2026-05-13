// main.cpp
// M5T2 - More Practice with Functions
// Lists numbers 1-10 alongside their squares using void and value-returning functions.

#include <iostream>
#include "m5t2.h"
using namespace std;

int main()
{
    cout << "Number\tSquare" << endl;
    cout << "------\t------" << endl;

    for (int i = 1; i <= 10; i++)
    {
        printAnswerLine(i);
    }

    return 0;
}

// Value-returning function: returns the square of num
int square(int num)
{
    return num * num;
}

// Void function: prints one formatted line showing num and its square
void printAnswerLine(int num)
{
    cout << num << "\t" << square(num) << endl;
}