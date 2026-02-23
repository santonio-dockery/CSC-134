// M3LAB1
// norrisa
// 2/23/26

#include <iostream>
#include <iomanip>
using namespace std;

// List PROTOTYPES of all the choices up here
// rename these to something that makes sense!
void picksword();
void picklance();
void pickshield();
void pickbow();

// main() goes here
int main() {

    string choice;
    // main() starts the game
    cout << "The Hero's Journey" << endl << endl;
    cout << "You're going about your day when suddenly your whisked into another world!" << endl;
    cout << "A Goddess meets and says you are the hero! She gives you the option to choose a weapon to save the world." << endl;
     cout << "Which would shall you pick:" << endl;
    cout << "Do You Pick a: " << endl; // make these into real choices!
    cout << "1. Sword" << endl;
    cout << "2. Lance" << endl;
    cout << "3. Shield" << endl;
     cout << "4. Bow" << endl;


    cout << "> "; // Give them a prompt to type
    cin >> choice;

    if ("Sword" == choice) {
        picksword();
       
    }
    else if ("Lance" == choice) {
        picklance();
    }
    else if ("Shield" == choice) {
        pickshield();
    }
    else if ("Bow" == choice) {
        pickbow();
    }
    else {
        cout << "Your teleported within an Ogre's den" << endl;
    }
    cout << "Ogres start surrounding you" << endl << endl;
    

    return 0; // end of game
}

// List FULL FUNCTIONS of all the choices at the bottom
void picksword() {
    cout << "You chose a sword." << endl;
    cout << "And then you are teleported to an ogre's den "; // you finish it!
    int choice;
    cin >> choice;
}

void picklance() {
    cout << "You chose a lance." << endl;
    cout << "And then you are teleported to an ogre's den "; // you finish it!
    int choice;
    cin >> choice;
}
void pickshield() {
    cout << "You chose a shield." << endl;
    cout << "And then you are teleported to an ogre's den "; // you finish it!
    int choice;
    cin >> choice;
}
void pickbow() {
    cout << "You chose a bow." << endl;
    cout << "And then you are teleported to an ogre's den "; // you finish it!
    int choice;
    cin >> choice;
    
}

// use the other choices in choice 1 or 2...