// CSC 134
// m2t1
//Santonio
/*
 We're selling "food" you decide
 tell the user how much you have
 how much each costs
 and what the total would be.
 As a store owner, I want to set uo my store,
 so that I can sell things and make $$$.

 If we have time we'll make it more interative
 */




#include <iostream>
//used for decimal point stuff
#include <iomanip>
using namespace std;

int main() {
    // declare variables at the top, easier to read
    string item_name = "burgers "; // change to anything you want to sell
    int item_count = 100;
    int purchased; //how many the user wants
    double price_each = 0.50;
    double total_price;

    //Part1: Set up the store
    // Note: right now items cant have spaces in their names
    cout << "Welcome to the store setup program." << endl;
    cout << "Name of item? ";
   getline(cin, item_name); //this should let us use spaces
    cout << "Number of items? ";
    cin >> item_count;
    cout << "Price each? ";
    cin >> price_each;



    // Part Two: Run the store(no changes)

    // set doubles to print with 2 decimal places
    cout << setprecision(2) << fixed;

    cout << "Welcome to our " << item_name << " store." << endl;
    cout << "We have " <<  item_count << " " <<  item_name << "." << endl;
    cout << "They cost $" << price_each << " each." << endl;
    
    // find out how much the user wants to buy
    cout << "How many would you like to buy?";
    cin >> purchased;

    //calculate the total
    total_price = purchased * price_each;

    cout << "Total price is $" << total_price << endl;
    return 0;
}