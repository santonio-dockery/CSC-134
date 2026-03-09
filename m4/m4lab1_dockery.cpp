/*
M4lab1 - loop in a loop
santoniod
3/9/26
*/

#include <iostream>
using namespace std;

int main() {
    //char is one character only, uses single quotes
    //char doesnt support unicode, only plain ASCII
    char symbol = '@';
    string emoji = "🍔";
    int height = 9;
    int width = 9;


    cout << "Enter height and width ( seperate with space): ";
    cin >> height >> width;
   

    // create a box of emoji symboles
    for (int i=0; i<width; i++) {
    cout << emoji;
    }
    cout << endl; //end of line

    for (int i=0; i<height; i++) {
        cout << emoji << endl;
    }

    //finally build the entire "box"
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++){
            cout << emoji << " ";
        }
        cout << endl;
    }
    
}