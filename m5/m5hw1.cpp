/*
 * CSC 134 - M5HW1
 * Gold Tier Solution (All 6 Questions)
 * All questions are implemented as functions, called from a main menu loop (Question 6).
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
// Question 1: Average Rainfall
// ─────────────────────────────────────────────
void question1() {
    string month1, month2, month3;
    double rain1, rain2, rain3;

    cout << "\n--- Question 1: Average Rainfall ---\n";

    cout << "Enter month: ";
    cin >> month1;
    cout << "Enter rainfall for " << month1 << ": ";
    cin >> rain1;

    cout << "Enter month: ";
    cin >> month2;
    cout << "Enter rainfall for " << month2 << ": ";
    cin >> rain2;

    cout << "Enter month: ";
    cin >> month3;
    cout << "Enter rainfall for " << month3 << ": ";
    cin >> rain3;

    double average = (rain1 + rain2 + rain3) / 3.0;

    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << month1 << ", " << month2
         << ", and " << month3 << " is " << average << " inches.\n";
}

// ─────────────────────────────────────────────
// Question 2: Volume of a Hyperrectangle (Block)
// ─────────────────────────────────────────────
void question2() {
    double width, length, height;

    cout << "\n--- Question 2: Volume of a Block ---\n";

    // Width with input validation
    do {
        cout << "Enter width: ";
        cin >> width;
        if (width <= 0)
            cout << "Error: Width must be greater than zero.\n";
    } while (width <= 0);

    // Length with input validation
    do {
        cout << "Enter length: ";
        cin >> length;
        if (length <= 0)
            cout << "Error: Length must be greater than zero.\n";
    } while (length <= 0);

    // Height with input validation
    do {
        cout << "Enter height: ";
        cin >> height;
        if (height <= 0)
            cout << "Error: Height must be greater than zero.\n";
    } while (height <= 0);

    double volume = width * length * height;
    cout << fixed << setprecision(2);
    cout << "The volume of the block is " << volume << " cubic units.\n";
}

// ─────────────────────────────────────────────
// Question 3: Roman Numerals (1–10)
// ─────────────────────────────────────────────
void question3() {
    int number;

    cout << "\n--- Question 3: Roman Numerals ---\n";

    // Input validation: must be 1–10
    do {
        cout << "Enter a number (1 - 10): ";
        cin >> number;
        if (number < 1 || number > 10)
            cout << "Error: Please enter a number between 1 and 10.\n";
    } while (number < 1 || number > 10);

    string roman;
    switch (number) {
        case 1:  roman = "I";    break;
        case 2:  roman = "II";   break;
        case 3:  roman = "III";  break;
        case 4:  roman = "IV";   break;
        case 5:  roman = "V";    break;
        case 6:  roman = "VI";   break;
        case 7:  roman = "VII";  break;
        case 8:  roman = "VIII"; break;
        case 9:  roman = "IX";   break;
        case 10: roman = "X";    break;
    }

    cout << "The Roman numeral version of " << number << " is " << roman << ".\n";
}

// ─────────────────────────────────────────────
// Question 4: Geometry Calculator
// ─────────────────────────────────────────────
void question4() {
    int choice;

    cout << "\n--- Question 4: Geometry Calculator ---\n";
    cout << "1. Calculate the Area of a Circle\n";
    cout << "2. Calculate the Area of a Rectangle\n";
    cout << "3. Calculate the Area of a Triangle\n";
    cout << "4. Quit (return to main menu)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    const double PI = 3.14159;

    if (choice == 1) {
        double radius;
        do {
            cout << "Enter the circle's radius: ";
            cin >> radius;
            if (radius < 0)
                cout << "The radius cannot be less than zero.\n";
        } while (radius < 0);
        cout << fixed << setprecision(5);
        cout << "The area is " << PI * radius * radius << "\n";

    } else if (choice == 2) {
        double length, width;
        do {
            cout << "Enter the rectangle's length: ";
            cin >> length;
            if (length < 0)
                cout << "Only enter positive values for length and width.\n";
        } while (length < 0);
        do {
            cout << "Enter the rectangle's width: ";
            cin >> width;
            if (width < 0)
                cout << "Only enter positive values for length and width.\n";
        } while (width < 0);
        cout << fixed << setprecision(2);
        cout << "The area is " << length * width << "\n";

    } else if (choice == 3) {
        double base, height;
        do {
            cout << "Enter the triangle's base: ";
            cin >> base;
            if (base < 0)
                cout << "Only enter positive values for base and height.\n";
        } while (base < 0);
        do {
            cout << "Enter the triangle's height: ";
            cin >> height;
            if (height < 0)
                cout << "Only enter positive values for base and height.\n";
        } while (height < 0);
        cout << fixed << setprecision(2);
        cout << "The area is " << base * height * 0.5 << "\n";

    } else if (choice == 4) {
        cout << "Returning to main menu.\n";

    } else {
        cout << "The valid choices are 1 through 4. Run the program again and select one of those.\n";
    }
}

// ─────────────────────────────────────────────
// Question 5: Distance Traveled
// ─────────────────────────────────────────────
void question5() {
    double speed;
    int hours;

    cout << "\n--- Question 5: Distance Traveled ---\n";

    // Input validation: speed must be >= 0
    do {
        cout << "What is the speed of the vehicle in mph? ";
        cin >> speed;
        if (speed < 0)
            cout << "Error: Speed cannot be negative.\n";
    } while (speed < 0);

    // Input validation: hours must be >= 1
    do {
        cout << "How many hours has it traveled? ";
        cin >> hours;
        if (hours < 1)
            cout << "Error: Time traveled must be at least 1 hour.\n";
    } while (hours < 1);

    cout << "\nHour   Distance Traveled\n";
    cout << "--------------------------------\n";

    for (int h = 1; h <= hours; h++) {
        cout << right << setw(4) << h
             << "   " << speed * h << "\n";
    }
}

// ─────────────────────────────────────────────
// Question 6: Main Menu Loop
// ─────────────────────────────────────────────
int main() {
    int choice;

    cout << "========================================\n";
    cout << "        CSC 134 - M5HW1 Main Menu       \n";
    cout << "========================================\n";

    do {
        cout << "\nSelect a question to run:\n";
        cout << "  1. Average Rainfall (Q1)\n";
        cout << "  2. Volume of a Block (Q2)\n";
        cout << "  3. Roman Numerals (Q3)\n";
        cout << "  4. Geometry Calculator (Q4)\n";
        cout << "  5. Distance Traveled (Q5)\n";
        cout << "  6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: question1(); break;
            case 2: question2(); break;
            case 3: question3(); break;
            case 4: question4(); break;
            case 5: question5(); break;
            case 6: cout << "Goodbye!\n"; break;
            default:
                cout << "Error: Please enter a number between 1 and 6.\n";
        }

    } while (choice != 6);

    return 0;
}