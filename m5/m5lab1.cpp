/*
CSC 134
m5lab1.cpp - The Hero's Journey (Main Program)
norrisa
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "m5lab1.h"
using namespace std;

// Utility Function Prototypes
int getPlayerChoice(int maxChoice);
void showChoices(string choice1, string choice2, string choice3);

int main() {
    srand(time(0));

    cout << "========================================" << endl;
    cout << "         THE HERO'S JOURNEY             " << endl;
    cout << "========================================" << endl;

    string play_again = "yes";

    while (play_again == "yes") {

        jam_start();

        cout << "\n----------------------------------------" << endl;
        cout << "Stats -> Wins: " << player_wins
             << " | Losses: " << player_losses
             << " | Games: "  << games_played << endl;
        cout << "----------------------------------------" << endl;
        cout << "Play again? (yes/no): ";
        cin >> play_again;
    }

    cout << "\n========================================" << endl;
    cout << "            FINAL RESULTS               " << endl;
    cout << "========================================" << endl;
    cout << "Games Played : " << games_played << endl;
    cout << "Wins         : " << player_wins   << endl;
    cout << "Losses       : " << player_losses << endl;

    if      (player_wins   > player_losses) cout << "The Goddess smiles. You were a true hero!" << endl;
    else if (player_losses > player_wins)   cout << "The Goddess shakes her head. Keep training, hero." << endl;
    else                                    cout << "The Goddess nods. A balanced hero. Not bad." << endl;

    cout << "Thanks for playing The Hero's Journey!" << endl;
    return 0;
}

// =============================================
// UTILITY FUNCTION DEFINITIONS
// =============================================

int getPlayerChoice(int maxChoice) {
    int choice;
    while (true) {
        cout << "Your choice (1-" << maxChoice << "): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (choice >= 1 && choice <= maxChoice) return choice;
        cout << "Choice out of range. Pick 1-" << maxChoice << "." << endl;
    }
}

void showChoices(string choice1, string choice2, string choice3) {
    cout << "\n--------------------------" << endl;
    if (choice1 != "") cout << "1. " << choice1 << endl;
    if (choice2 != "") cout << "2. " << choice2 << endl;
    if (choice3 != "") cout << "3. " << choice3 << endl;
    cout << "--------------------------" << endl;
}