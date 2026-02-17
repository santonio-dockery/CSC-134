/*
m2hw1
Santonio Dockery
CSC-134
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {   
     string name;
     
     int acc_num = 53467;
    double acc_balance, deposit, withdraw, final_balance;


cout << setprecision(2) << fixed;


cout << "Question 1" << endl;
cout << endl;
cout << "What is your name: "; 
getline(cin, name); 
cout << "Account Balance:";
cin >> acc_balance;
cout << "Deposit:";
cin >> deposit;
cout << "Withdrawal:";
cin >> withdraw;

final_balance = acc_balance - withdraw + deposit;

cout << "Account Name:" << name << endl;
cout << "Account Number:" << acc_num << endl;
cout << "Final Balance:" << final_balance << endl;
cout << endl;

cout << "Question 2" << endl;
cout << endl;
// Part 1 -Set up variables
    // Crate variables
    double length, width, height, volume; // in feet
    // price variables
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;
    double cost, customer_price, profit; // In $

    // Part 2 - Input
    cout << "Crate Purchase Program" << endl;
    cout << "Enter the size of your crate \n";
    cout << "Length?";
    cin >> length;
    cout << "Width?";
    cin >> width;
    cout << "Height?";
    cin >> height;

    //Part 3-Calculations
    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    customer_price = volume * CHARGE_PER_CUBIC_FOOT;
    profit = customer_price - cost;

    // Part 4 -Output
    cout << setprecision(2) << fixed; //2 decimal places
    cout << "\n---- CRATE INFO ----\n";
    cout << "Volume: " << volume << " cubic feet." << endl;
    cout << "Cost to make: $" << cost << endl;
    cout << "Retail Price: $" << customer_price << endl;
    cout << "Profit:     $" << profit << endl << endl;
    cout << endl;



   

    cout << "Question 3" << endl;
cout << endl;
 int boxes, slices, visitors, total_slices, slices_eaten, final_pieces;


cout << "How many boxes?:";
cin >> boxes;
cout << "How many slices per pizza?:";
cin >> slices;
cout << "How many people are attenging?:";
cin >> visitors;

total_slices = boxes * slices;
slices_eaten = visitors * 3;
final_pieces = total_slices - slices_eaten;

cout << "Leftover slices:" << final_pieces << endl;



string LetsGo, team, school, cheerOne, cheerTwo;
  LetsGo = "Let's go ";
 school = "FTCC";
 team = "Trojans";
cheerOne = LetsGo + school;
cheerTwo = LetsGo + team;
 
 cout << "Question 4" << endl;
cout << endl;
cout << cheerOne << endl;
cout << cheerOne << endl;
cout << cheerOne << endl;
cout << cheerTwo << endl;

return 0;



}

