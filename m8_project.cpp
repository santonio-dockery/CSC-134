/*
CSC 134
M8 Final Project - The Hero's Journey (Extended)
Student Name: [Your Name]
Features added: Leveling System, Fixed Input Handling, Enhanced Endings.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// =============================================
// Global Player Data & Stats
// =============================================
string weapon_name     = "";
int    weapon_strength = 0;
int    player_wins     = 0;
int    player_losses   = 0;
int    games_played    = 0;
int    player_xp       = 0;
int    player_level    = 1;
int    max_hp_bonus    = 0;

// =============================================
// Function Prototypes
// =============================================
void jam_start();
void path_divine_gift();
void path_the_village();
void path_the_shrine();
void start_battle();
void pick_sword();
void pick_lance();
void pick_bow();
void pick_shield();
void ending_victory(int player_hp);
void ending_defeat();

// Utilities
int getPlayerChoice(int maxChoice);
void showChoices(string c1, string c2, string c3);

// =============================================
// MAIN EXECUTION
// =============================================
int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "========================================" << endl;
    cout << "         THE HERO'S JOURNEY             " << endl;
    cout << "========================================" << endl;

    string play_again = "yes";
    while (play_again == "yes" || play_again == "y") {
        jam_start();

        cout << "\n----------------------------------------" << endl;
        cout << "Stats -> Level: " << player_level << " (" << player_xp << " XP)" << endl;
        cout << "Wins: " << player_wins << " | Losses: " << player_losses << endl;
        cout << "----------------------------------------" << endl;
        cout << "Play again? (yes/no): ";
        cin >> play_again;
    }

    cout << "\nFinal Level achieved: " << player_level << endl;
    cout << "Thanks for playing!" << endl;
    return 0;
}

// =============================================
// STORY LOGIC
// =============================================

void jam_start() {
    cout << R"(
========================================
You're whisked into another world!
A Goddess appears: "Hero, the Ogre terrorizes
our lands. Will you stand against it?"
========================================
    )" << endl;

    games_played++;
    weapon_name = "";
    weapon_strength = 0;

    cout << "Game " << games_played << " | Level " << player_level << " begins!" << endl;
    showChoices("Head straight for the ogre's den.",
                "Stop at the nearby village first.",
                "Investigate a glowing shrine.");

    int choice = getPlayerChoice(3);
    if (choice == 1) path_divine_gift();
    else if (choice == 2) path_the_village();
    else path_the_shrine();
}

void path_divine_gift() {
    cout << "\nThe Goddess offers a weapon from her armory:" << endl;
    cout << "1. Sword (Aggressive) | 2. Lance (Control) | 3. Bow (Tactical) | 4. Shield (Defense)" << endl;
    int choice = getPlayerChoice(4);
    if (choice == 1) pick_sword();
    else if (choice == 2) pick_lance();
    else if (choice == 3) pick_bow();
    else pick_shield();
}

void path_the_village() {
    cout << "\n--- THE VILLAGE OF ELDMERE ---" << endl;
    showChoices("Talk to the blacksmith.", "Listen to the old woman.", "Follow the child.");
    int choice = getPlayerChoice(3);
    if (choice == 1) { cout << "The smith gives you a Heated Blade!"; pick_sword(); }
    else if (choice == 2) { cout << "The woman gives you an Elder Bow!"; pick_bow(); }
    else { cout << "The child finds a Dragon Shield!"; pick_shield(); }
}

void path_the_shrine() {
    cout << "\n--- THE SHRINE OF ECHOES ---" << endl;
    showChoices("Offer Courage (Any Weapon).", "Offer Caution (Lance + Blessing).", "Leave.");
    int choice = getPlayerChoice(3);
    if (choice == 1) path_divine_gift();
    else if (choice == 2) { weapon_strength = 50; pick_lance(); }
    else { cout << "The Goddess sighs and hands you a sword anyway."; pick_sword(); }
}

// =============================================
// WEAPON SETTERS
// =============================================
void pick_sword() { weapon_name = "Sword"; if (weapon_strength < 50) weapon_strength = 20; start_battle(); }
void pick_lance() { weapon_name = "Lance"; if (weapon_strength < 50) weapon_strength = 10; start_battle(); }
void pick_bow()   { weapon_name = "Bow";   if (weapon_strength < 50) weapon_strength = 5;  start_battle(); }
void pick_shield(){ weapon_name = "Shield";if (weapon_strength < 50) weapon_strength = 1;  start_battle(); }

// =============================================
// COMBAT ENGINE
// =============================================
void start_battle() {
    int player_hp = 100 + max_hp_bonus;
    int ogre_hp = 140;
    int round = 1;
    int momentum = 0;
    bool surge_available = false;
    bool player_open = false;
    bool player_dodging = false;
    bool ogre_taunted = false;
    bool aimed_shot_ready = false;
    bool counter_ready = false;

    if (weapon_strength >= 50) { ogre_hp -= 20; cout << "[BLESSING: Ogre weakened!]" << endl; }

    while (player_hp > 0 && ogre_hp > 0) {
        cout << "\n--- Round " << round << " | HP: " << player_hp << " | Ogre: " << ogre_hp << " ---" << endl;
        cout << "Momentum: [" << momentum << "/3] " << (surge_available ? "!!SURGE READY!!" : "") << endl;

        // Simplified choice display based on weapon
        if (weapon_name == "Sword") cout << "1.Slash 2.Heavy 3.Lunge 4.Roar";
        else if (weapon_name == "Lance") cout << "1.Jab 2.Brace 3.Shove 4.Spin";
        else if (weapon_name == "Bow") cout << "1.Shot 2.Aim 3.Scatter 4.Roll";
        else cout << "1.Bash 2.Brace 3.Counter 4.Taunt";
        if (surge_available) cout << " 5.SURGE";
        cout << endl;

        int choice = getPlayerChoice(surge_available ? 5 : 4);
        int damage_dealt = 0;
        player_dodging = false;

        // Logic for SURGE
        if (choice == 5) {
            damage_dealt = 35; // Standardized surge
            ogre_hp -= damage_dealt;
            surge_available = false; momentum = 0;
            cout << "SURGE! You unleash a devastating combo for " << damage_dealt << " damage!" << endl;
        } else {
            // Standard Attack Logic
            damage_dealt = rand() % 15 + 10;
            if (choice == 4) { ogre_taunted = true; damage_dealt = 0; cout << "You taunt the ogre!" << endl; }
            else if (choice == 2 && weapon_name == "Shield") { player_dodging = true; damage_dealt = 0; counter_ready = true; }
            else { ogre_hp -= damage_dealt; cout << "You hit for " << damage_dealt << "!" << endl; }
        }

        // Ogre Attack
        if (ogre_hp > 0 && !player_dodging) {
            int ogre_dmg = rand() % 15 + 5;
            if (ogre_taunted) ogre_dmg -= 5;
            player_hp -= ogre_dmg;
            cout << "Ogre hits you for " << ogre_dmg << "!" << endl;
        } else if (player_dodging) {
            cout << "You blocked the Ogre's attack!" << endl;
        }

        if (damage_dealt > 0 && momentum < 3) momentum++;
        if (momentum >= 3) surge_available = true;
        
        ogre_taunted = false;
        round++;
    }

    if (player_hp > 0) ending_victory(player_hp);
    else ending_defeat();
}

void ending_victory(int player_hp) {
    cout << "\nVICTORY! You defeated the ogre!" << endl;
    player_wins++;
    int gain = 50;
    player_xp += gain;
    cout << "Gained " << gain << " XP!" << endl;
    if (player_xp >= 100) {
        player_level++;
        player_xp = 0;
        max_hp_bonus += 20;
        cout << "LEVEL UP! You are now Level " << player_level << "! (Max HP increased)" << endl;
    }
}

void ending_defeat() {
    cout << "\nDEFEAT! The Goddess revives you, but the ogre remains..." << endl;
    player_losses++;
}

// =============================================
// UTILITIES
// =============================================
void showChoices(string c1, string c2, string c3) {
    cout << "\n1. " << c1 << "\n2. " << c2 << "\n3. " << c3 << endl;
}

int getPlayerChoice(int maxChoice) {
    int choice;
    while (true) {
        cout << "Choice (1-" << maxChoice << "): ";
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(100, '\n');
            continue;
        }
        if (choice >= 1 && choice <= maxChoice) return choice;
    }
}