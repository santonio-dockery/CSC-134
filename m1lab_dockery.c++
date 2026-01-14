// CSC 134
// m1lab-sales
//Santonio

#include <iostream>
using namespace std;

int main() {
    // declare variables at the top, easier to read
    string item = "bananas"; // change to anything you want to sell
    int item_count = 100;
    double price_each = 0.79;
    double total_price;

    cout << "Welcome to our " << item << " store." << endl;
    cout << "We have " <<  item_count <<  item << "." << endl;
    cout << "They cost $" << price_each << " each." << endl;

    //calculate the total
    total_price = item_count * price_each;

    cout << "Total price is $" << total_price << endl;
    return 0;
}