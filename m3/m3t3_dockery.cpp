/*
csc 134
m3t3-craps and randon numbers 
Santonio Dockery
2/18/26*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function prototype -declare whats coming
int roll(); // returns number 1-6

int main() {
    //seed the RNG
    srand(time(0));
    //set up variables
    int roll1, roll2 , total, point;
    string status; // win, lose,

    roll1 = roll();
    roll2 = roll();
    total = roll1 + roll2;

    //print the dice roll
    cout << "Roll is: " << roll1 << " + " << roll2 << " = " << total << endl;

    // determine win or loss
    if (total == 7 || total == 11) { // || is OR
        status = "win";
    }
    else if (total == 2 || total == 3 || total == 12) {
        status = "lose";
    }
    else {
        // point 
        point = total; //save for later
        status = "point";
    }

    cout << "Roll results: " << status << endl;
    // handle the point case
    if (status == "point") {
        cout << "Point is " << point << endl;
        cout << "Roll " << point << " before a 7!" << endl;

        bool finished = false;
        while (!finished) {
            total = roll() + roll();
            if (total == point) {
                cout <<  "Rolled " << total << " you win!" << endl;
                finished = true;
            }
            else if (total == 7) {
                cout << "Rolled " << total << " you lose!" << endl;
                finished = true;
                
            }
            else {
                cout << "Rolled " << total << " -- roll again" << endl;
            }
        }
    }

    
    return 0;
}
// funtion definition - the whole thing
int roll() {
    //returns number from 1-6
    int num = (rand() % 6) + 1;
    return num;
}