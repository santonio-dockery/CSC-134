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
void start_battle();

// Global Data
string weapon_name;
int weapon_strength;


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
    
    

    return 0; // end of game
}

// List FULL FUNCTIONS of all the choices at the bottom
void picksword() {
    cout << "You chose a sword." << endl;
    cout << "You are then teleported to an ogre's den! "; // you finish it!
    weapon_name = "Sword";
    weapon_strength = 20;
    start_battle(); // TODO, write this
}

void picklance() {
    cout << "You chose a lance." << endl;
    cout << "You are then teleported to an ogre's den! "; // you finish it!
     weapon_name = "Lance";
    weapon_strength = 10;
    start_battle(); // TODO, write this
}

void pickshield() {
    cout << "You chose a shield." << endl;
    cout << "You are then teleported to an ogre's den! "; // you finish it!
     weapon_name = "Shield";
    weapon_strength = 1;
    start_battle(); // TODO, write this
}

void pickbow() {
    cout << "You chose a bow." << endl;
    cout << "You are then teleported to an ogre's den! "; // you finish it!
    weapon_name = "Bow";
    weapon_strength = 5;
    start_battle(); // TODO, write this
}
void start_battle() {
    cout << "You enter the battle with a " << weapon_name << "!" << endl;
    cout << "Your weapon strength is " << weapon_strength << endl;
    if (weapon_strength > 5) {
        cout << "You defeated the ogres" << endl;
    }
    else {
        cout << "You were killed by the ogres" << endl;
    }
}
    


// use the other choices in choice 1 or 2...