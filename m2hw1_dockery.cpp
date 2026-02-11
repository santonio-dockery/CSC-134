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
     string name2 = "Santonio Dockery";
     int acc_num = 53467;
    double acc_balance, deposit, withdraw, final_balance;


cout << setprecision(2) << fixed;


cout << "Question 1" << endl;
cout << endl;
cout << "What is your name: "; 
cin >> name;
cout << "Account Balance:";
cin >> acc_balance;
cout << "Deposit:";
cin >> deposit;
cout << "Withdrawal:";
cin >> withdraw;

final_balance = acc_balance - withdraw + deposit;

cout << "Account Name:" << name2 << endl;
cout << "Account Number:" << acc_num << endl;
cout << "Final Balance:" << final_balance << endl;








}

