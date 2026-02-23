// M3LAB1
// norrisa
// 2/23/26

#include <iostream>
using namespace std;

// List PROTOTYPES of all the choices up here
// rename these to something that makes sense!
void pickword();
void picklance();
void pick_shield();
void pick_bow();

// main() goes here
int main() {

    int choice;
    // main() starts the game
    cout << "GAME TITLE" << endl << endl;
    cout << "You're going about your day when suddenly something happens..." << endl;
    cout << "Do You: " << endl; // make these into real choices!
    cout << "1. Choice #1" << endl;
    cout << "2. Choice #2" << endl;

    cout << "> "; // Give them a prompt to type
    cin >> choice;

    if (1 == choice) {
        pickword();
    }
    else if (2 == choice) {
        picklance();
    }
    else {
        cout << "I didn't understand that." << endl;
    }
    cout << "*GAME OVER*" << endl << endl;

    return 0; // end of game
}

// List FULL FUNCTIONS of all the choices at the bottom
void pickword() {
    cout << "You make the first choice." << endl;
    cout << "And then..."; // you finish it!
}

void picklance() {
    cout << "You make the second choice." << endl;
    cout << "And then..."; // you finish it!
}

// use the other choices in choice 1 or 2...