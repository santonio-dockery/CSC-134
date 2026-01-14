// CSC 134
// m1lab-sales
//Santonio
/*
 We're selling "food" you decide
 tell the user how much you have
 how much each costs
 and what the total would be.

 If we have time we'll make it more interative
 */




#include <iostream>
//used for decimal point stuff
#include <iomanip>
using namespace std;

int main() {
    // declare variables at the top, easier to read
    string item = "burgers "; // change to anything you want to sell
    int item_count = 100;
    int purchased; //how many the user wants
    double price_each = 0.50;
    double total_price;

    // set doubles to print with 2 decimal places
    cout << setprecision(2) << fixed;

    cout << "Welcome to our " << item << " store." << endl;
    cout << "We have " <<  item_count << " " <<  item << "." << endl;
    cout << "They cost $" << price_each << " each." << endl;
    
    // find out how much the user wants to buy
    cout << "How many would you like to buy?";
    cin >> purchased;

    //calculate the total
    total_price = purchased * price_each;

    cout << "Total price is $" << total_price << endl;
    return 0;
}