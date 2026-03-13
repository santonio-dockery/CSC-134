/*
CSC-134
M3HW1-Gold
Santoniod
3/8/26
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

string answer;

int main() {
    
    cout << "Question 1" << endl;
    cout << endl;
    cout << "Hello, I'm a C++ Program!" << endl;
    cout << "Do you like me? Please type yes or no: ";
    cin >> answer;

    if (answer == "yes") {
        cout << "That's great I'm sure we'll get along" << endl;
    }
    else if (answer == "no") {
        cout << "Well, maybe you'll learn to like me later." << endl;
    }
    else {
        cout << "If you're not sure, that's ok" << endl;
    }

    cout << endl;

    //variables
    string meal_name = "Carolina BBQ Burger";
    double meal_price;
    int meal_count;

    double subtotal, tip, tax_amount, total;
    const double TAX_RATE = 0.07;
    const double TIP_RATE = 0.15;
    int dine_to;

    // take the order
    cout << "Question 2" << endl;
    cout << endl;
    cout << "Welcome to the Restaurant" << endl;
    cout << "How many " << meal_name << " would you like?" << endl;
    cin >> meal_count;

    cout << "What is the price of your meal: ";
    cin >> meal_price;

    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
    cin >> dine_to;

    cout << "Preparing your order..." << endl << endl;

    // calculate subtotal
    subtotal = meal_price * meal_count;

    // calculate tax
    tax_amount = subtotal * TAX_RATE;

    // tip only if dine in
    if (dine_to == 1) {
        tip = subtotal * TIP_RATE;
    }
    else {
        tip = 0;
    }

    // total
    total = subtotal + tax_amount + tip;

    // print receipt
    cout << fixed << setprecision(2);
    cout << "-------------------------------" << endl;
    cout << meal_name << " X " << meal_count << endl;
    cout << "SUBTOTAL:\t\t$" << subtotal << endl;
    cout << "Tax:\t\t\t$" << tax_amount << endl;
    cout << "Tip:\t\t\t$" << tip << endl;
    cout << "-------------------------------" << endl;
    cout << "Total:\t\t\t$" << total << endl;
    cout << "THANK YOU COME AGAIN" << endl;

    cout << endl;

    // Question 3
    cout << "Question 3" << endl;
    cout << endl;

    string choice1;
    string choice2;

    cout << "You are walking in the forest." << endl;
    cout << "Do you:" << endl;
    cout << "1. Enter a dark cave" << endl;
    cout << "2. Go back home" << endl;
    cin >> choice1;

    if (choice1 == "2") {
        cout << "You went home. Game Over." << endl;
    }
    else if (choice1 == "1") {

        cout << "Inside the cave you see a dragon!" << endl;
        cout << "Do you:" << endl;
        cout << "1. Fight the dragon" << endl;
        cout << "2. Run away" << endl;
        cin >> choice2;

        if (choice2 == "1") {
            cout << "You defeated the dragon! Victory!" << endl;
        }
        else {
            cout << "The dragon caught you. Defeat." << endl;
        }
    }

    cout << endl;

    // Question 4
    cout << "Question 4" << endl;
    cout << endl;

    srand(time(0));

    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int user_answer;

    cout << "What is " << num1 << " plus " << num2 << "?" << endl;
    cin >> user_answer;

    if (user_answer == num1 + num2) {
        cout << "Correct." << endl;
    }
    else {
        cout << "Incorrect." << endl;
    }

}