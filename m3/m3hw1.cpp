/*
CSC-134
M3HW1-Gold
Santoniod
3/8/26
*/


#include <iostream>
#include <iomanip>
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
    cout << "If your not sure, that's ok" << endl;
    }



    //variables
    string meal_name = "Carolina BBQ Burger";
    double meal_price;
    int  meal_count;// do they want 1 or 2 receipt stuff
    //the reciept stuff
    double subtotal, tip, tax_amount, total; //all in $
    const double TAX_RATE = 0.07; // 7% is 7/100
    int dine_to;

// take the order
cout << "Question 2" << endl;
cout << endl;
cout << "Welcome to the Restaurant" << endl;
cout << "How many " << meal_name << " would you like?" << endl;
cin >> meal_count;
cout << "What is the price of your meal: ";
cin >> meal_price;
cout << "Please enter 1 if the order is dine in, 2 if it is to go";
cin >> dine_to;
if (dine_to == 1) {
    
}
cout << "Preparing you order..." << endl << endl;

// calculate the subtotal and total 
subtotal = meal_price * meal_count; // before taxes and tip
tax_amount = subtotal * TAX_RATE; // $ in taxes
total = subtotal + tax_amount;

// print the receipt
cout << setprecision(2) << fixed;
cout << "-------------------------------" << endl;
cout << meal_name << " X " << meal_count  << endl;
cout << "SUBTOTAL: \t\t$" << subtotal     << endl;
cout << "Tax: \t\t$"      << tax_amount   << endl;
cout << "-------------------------------" << endl;
cout << "Total: \t\t\t$"  << total        << endl;
cout << "THANK YOU COME AGAIN" << endl;




}

