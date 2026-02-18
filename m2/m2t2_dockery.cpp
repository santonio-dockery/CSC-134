/*
CSC 134
M2T2 - Receipt
Santonio Dockery
1/28/26
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main () {

    //variables
    string meal_name = "Carolina BBQ Burger";
    double meal_price =5.99;
    int  meal_count;// do they want 1 or 2 receipt stuff
    //the reciept stuff
    double subtotal, tip, tax_amount, total; //all in $
    const double TAX_RATE = 0.07; // 7% is 7/100

// take the order
cout << "Welcome to the Restaurant" << endl;
cout << "How many " << meal_name << " would you like?" << endl;
cin >> meal_count;
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