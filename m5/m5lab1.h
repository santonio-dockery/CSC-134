/*
CSC 134
m5lab1.h - The Hero's Journey (Story + Combat)
norrisa
*/

#ifndef M5LAB1_H
#define M5LAB1_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// =============================================
// Utility function prototypes (defined in .cpp)
// =============================================
extern void showChoices(string, string, string);
extern int getPlayerChoice(int);

// =============================================
// Global Player Data
// =============================================
string weapon_name     = "";
int    weapon_strength = 0;
int    player_wins     = 0;
int    player_losses   = 0;
int    games_played    = 0;

// =============================================
// Story + Combat Branch Prototypes
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

// =============================================
// STORY FUNCTIONS
// =============================================

void jam_start() {
    cout << R"(
========================================
         THE HERO'S JOURNEY
========================================
You're going about your day when suddenly
you're whisked into another world!
A Goddess appears and says YOU are the hero.
An ancient ogre has been terrorizing the land,
and only you can stop it.
========================================
    )" << endl;

    games_played++;
    weapon_name    = "";
    weapon_strength = 0;

    cout << "Game " << games_played << " begins!" << endl;
    cout << "\nBefore you face the ogre, what do you do?" << endl;

    showChoices("Head straight for the ogre's den.",
                "Stop at the nearby village first.",
                "Investigate a glowing shrine on the hillside.");

    int choice = getPlayerChoice(3);

    if      (choice == 1) path_divine_gift();
    else if (choice == 2) path_the_village();
    else                  path_the_shrine();
}

// --- Story Branch: Divine Gift (straight to weapon pick) ---
void path_divine_gift() {
    cout << "\nThe Goddess appears in a flash of light!" << endl;
    cout << "She offers you a weapon from her armory. Choose wisely!\n" << endl;
    cout << "--------------------------" << endl;
    cout << "1. Sword  - High damage, aggressive options" << endl;
    cout << "2. Lance  - Range control, keep the ogre at bay" << endl;
    cout << "3. Bow    - Tactical setup, hit hard from a distance" << endl;
    cout << "4. Shield - Outlast and punish, turn defense into offense" << endl;
    cout << "--------------------------" << endl;

    int choice = getPlayerChoice(4);

    if      (choice == 1) pick_sword();
    else if (choice == 2) pick_lance();
    else if (choice == 3) pick_bow();
    else                  pick_shield();
}

// --- Story Branch: The Village ---
void path_the_village() {
    cout << R"(
--- THE VILLAGE OF ELDMERE ---
You arrive at a dusty village. The people look terrified.
A blacksmith, an old woman, and a frightened child all try
to get your attention at once.
    )" << endl;

    showChoices("Talk to the blacksmith.",
                "Listen to the old woman.",
                "Follow the child.");

    int choice = getPlayerChoice(3);

    if (choice == 1) {
        cout << "\nThe blacksmith grabs you by the arm." << endl;
        cout << "\"Take this. It's the best blade I've ever forged.\"" << endl;
        cout << "He hands you a Sword that practically glows with heat." << endl;
        cout << "\"That ogre took my son. Make it pay.\"" << endl;
        pick_sword();
    }
    else if (choice == 2) {
        cout << "\nThe old woman squints at you with sharp eyes." << endl;
        cout << "\"The ogre fears one thing -- distance. Hit it before it hits you.\"" << endl;
        cout << "She presses a Bow into your hands, arrows already quivered." << endl;
        cout << "\"I made every one of those arrowheads myself.\"" << endl;
        pick_bow();
    }
    else {
        cout << "\nThe child leads you behind a crumbled barn." << endl;
        cout << "Buried under hay is a battered Shield, cracked but solid." << endl;
        cout << "\"My dad said this blocked a dragon once,\" the child whispers." << endl;
        cout << "Whether that's true or not -- it's yours now." << endl;
        pick_shield();
    }
}

// --- Story Branch: The Shrine ---
void path_the_shrine() {
    cout << R"(
--- THE SHRINE OF ECHOES ---
You climb the hill and find a stone shrine humming with energy.
Offerings from past heroes litter the ground: broken swords,
burned arrows, a shield split clean in two.
A voice echoes from the stone.
"Choose your offering."
    )" << endl;

    showChoices("Offer your courage (choose any weapon).",
                "Offer your caution (receive the Lance, and a blessing).",
                "Take nothing and leave.");

    int choice = getPlayerChoice(3);

    if (choice == 1) {
        cout << "\nThe shrine glows. \"Courage. Very well.\"" << endl;
        cout << "Four weapons materialize before you." << endl;
        path_divine_gift();
    }
    else if (choice == 2) {
        cout << "\nThe shrine glows a calm blue." << endl;
        cout << "\"Caution is wisdom. Take this.\"" << endl;
        cout << "A Lance appears -- and you feel strangely focused." << endl;
        cout << "\n*** SHRINE BLESSING: The ogre starts with 20 less HP! ***" << endl;
        weapon_strength = 50; // flag picked up in start_battle
        pick_lance();
    }
    else {
        cout << "\nYou walk away. The shrine goes silent." << endl;
        cout << "The Goddess sighs and hands you a sword." << endl;
        cout << "\"At least take something, hero.\"" << endl;
        pick_sword();
    }
}

// =============================================
// WEAPON PICK FUNCTIONS
// =============================================

void pick_sword() {
    weapon_name = "Sword";
    if (weapon_strength < 50) weapon_strength = 20;
    cout << "\nYou grab the Sword. It hums with power in your grip." << endl;
    cout << "You are teleported to the ogre's den!" << endl;
    start_battle();
}

void pick_lance() {
    weapon_name = "Lance";
    if (weapon_strength < 50) weapon_strength = 10;
    cout << "\nYou grab the Lance. It's longer than you expected." << endl;
    cout << "You are teleported to the ogre's den!" << endl;
    start_battle();
}

void pick_bow() {
    weapon_name = "Bow";
    if (weapon_strength < 50) weapon_strength = 5;
    cout << "\nYou grab the Bow and a quiver of arrows." << endl;
    cout << "You are teleported to the ogre's den!" << endl;
    start_battle();
}

void pick_shield() {
    weapon_name = "Shield";
    if (weapon_strength < 50) weapon_strength = 1;
    cout << "\nYou grab the Shield. It's heavier than it looks." << endl;
    cout << "You are teleported to the ogre's den!" << endl;
    start_battle();
}

// =============================================
// COMBAT SYSTEM
// =============================================

void start_battle() {
    int player_hp = 100;
    int ogre_hp   = 140;

    // Shrine blessing check
    if (weapon_strength >= 50 && weapon_name == "Lance") {
        ogre_hp -= 20;
        cout << "\n[Shrine Blessing: The ogre recoils as you enter!]" << endl;
        cout << "[Ogre starts at " << ogre_hp << " HP instead of 140!]" << endl;
        weapon_strength = 10;
    }

    int  round           = 1;
    bool enraged         = false;
    bool player_open     = false;
    bool ogre_taunted    = false;
    bool player_dodging  = false;
    bool ogre_slowed     = false;
    bool aimed_shot_ready = false;
    bool counter_ready   = false;
    int  momentum        = 0;
    bool surge_available = false;

    int base_min, base_max;
    if      (weapon_name == "Sword")  { base_min = 14; base_max = 22; }
    else if (weapon_name == "Lance")  { base_min = 12; base_max = 20; }
    else if (weapon_name == "Bow")    { base_min = 10; base_max = 18; }
    else if (weapon_name == "Shield") { base_min = 10; base_max = 18; }
    else                              { base_min = 4;  base_max = 8;  }

    int ogre_min = 10;
    int ogre_max = 20;

    string action;

    cout << "\n========================================" << endl;
    cout << "  A massive ogre blocks your path!" << endl;
    cout << "  Your weapon: " << weapon_name << endl;
    cout << "  Your HP: " << player_hp << " | Ogre HP: " << ogre_hp << endl;
    cout << "========================================" << endl;

    while (player_hp > 0 && ogre_hp > 0) {

        // Enrage at 50% HP
        if (!enraged && ogre_hp <= 70) {
            enraged   = true;
            ogre_min += 5;
            ogre_max += 5;
            cout << "\n  *** THE OGRE ENRAGES! ***" << endl;
            cout << "  Its wounds drive it into a frenzy!" << endl;
            cout << "  Ogre damage is now " << ogre_min << "-" << ogre_max << "." << endl;
        }

        cout << "\n--- Round " << round << " ---" << endl;
        cout << "Your HP: " << player_hp << " | Ogre HP: " << ogre_hp << endl;

        // Momentum display
        cout << "Momentum: ";
        for (int i = 0; i < momentum; i++)       cout << "[*]";
        for (int i = momentum; i < 3; i++)        cout << "[ ]";
        cout << endl;

        if (surge_available)   cout << "  *** SURGE READY! Use option 5! ***" << endl;
        if (aimed_shot_ready)  cout << "  [Locked in -- next shot hits HARD!]" << endl;

        cout << "\nWhat do you do?" << endl;

        // Show options
        if (weapon_name == "Sword") {
            cout << "1. Slash        - Balanced strike, decent crit chance" << endl;
            cout << "2. Heavy Strike - Huge damage, but you're wide open after" << endl;
            cout << "3. Lunge        - High crit, high miss -- go big or go home" << endl;
            cout << "4. Intimidate   - No damage, ogre misses more next round" << endl;
            if (surge_available)
            cout << "5. SURGE        - Rapid triple strike!" << endl;
        }
        else if (weapon_name == "Lance") {
            cout << "1. Jab          - Quick poke from safe range" << endl;
            cout << "2. Brace & Thrust - Guaranteed hit, no dodge possible after" << endl;
            cout << "3. Shove        - Push back for small damage, ogre stumbles" << endl;
            cout << "4. Spin Strike  - Random: could be massive or self-damage" << endl;
            if (surge_available)
            cout << "5. SURGE        - Pin the ogre and drive through!" << endl;
        }
        else if (weapon_name == "Bow") {
            cout << "1. Quick Shot   - Always fires, lower damage" << endl;
            cout << "2. Aim          - Skip damage, next shot is massive" << endl;
            cout << "3. Scatter Shot - Guaranteed moderate hit" << endl;
            cout << "4. Roll Back    - Dodge + small shot" << endl;
            if (surge_available)
            cout << "5. SURGE        - Rapid-fire quiver dump!" << endl;
        }
        else if (weapon_name == "Shield") {
            cout << "1. Bash         - Reliable, low damage" << endl;
            cout << "2. Brace        - Block all damage, set up Counter" << endl;
            cout << "3. Counter      - Explosive only after Brace!" << endl;
            cout << "4. Taunt        - Provoke wild swings next round" << endl;
            if (surge_available)
            cout << "5. SURGE        - Bull rush the ogre!" << endl;
        }
        else {
            cout << "1. Punch  2. Flail  3. Duck  4. Yell" << endl;
        }

        cout << "> ";
        cin >> action;

        player_dodging = false;
        player_open    = false;
        int damage_dealt = 0;

        // ============================
        // SURGE (option 5)
        // ============================
        if (action == "5" && surge_available) {
            surge_available = false;
            momentum        = 0;
            if (weapon_name == "Sword") {
                int total = 0;
                cout << "\nYou channel pure momentum into three rapid strikes!" << endl;
                for (int i = 1; i <= 3; i++) {
                    int d = rand() % (base_max - base_min + 1) + base_min;
                    total += d;
                    cout << "  Strike " << i << ": " << d << " damage!" << endl;
                }
                ogre_hp     -= total;
                damage_dealt = total;
                cout << "SURGE TOTAL: " << total << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (weapon_name == "Lance") {
                int d = rand() % 20 + 25;
                ogre_hp     -= d;
                damage_dealt = d;
                cout << "\nYou drive the lance in deep and TWIST!" << endl;
                cout << "SURGE PIN: " << d << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (weapon_name == "Bow") {
                int total = 0;
                cout << "\nYou empty the quiver in a storm of arrows!" << endl;
                for (int i = 1; i <= 4; i++) {
                    int d = rand() % 10 + 6;
                    total += d;
                    cout << "  Arrow " << i << ": " << d << " damage!" << endl;
                }
                ogre_hp     -= total;
                damage_dealt = total;
                cout << "SURGE VOLLEY: " << total << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (weapon_name == "Shield") {
                int d = rand() % 18 + 20;
                ogre_hp     -= d;
                damage_dealt = d;
                cout << "\nYou sprint and SLAM the shield like a battering ram!" << endl;
                cout << "SURGE RUSH: " << d << " damage! Ogre HP: " << ogre_hp << endl;
            }
        }

        // ============================
        // SWORD ACTIONS
        // ============================
        else if (weapon_name == "Sword") {
            if (action == "1") {
                int dmg = rand() % (base_max - base_min + 1) + base_min;
                int hit = rand() % 100 + 1;
                if (hit <= 10) {
                    cout << "\nYour slash is deflected. No damage." << endl;
                }
                else if (hit >= 88) {
                    dmg *= 2;
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nCRITICAL! Your sword finds a gap in the ogre's hide!" << endl;
                    cout << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                }
                else {
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nClean slash for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }
            else if (action == "2") {
                int dmg = rand() % (base_max - base_min + 1) + base_min + 10;
                int hit = rand() % 100 + 1;
                if (hit <= 20) {
                    cout << "\nYou wind up... and the ogre sidesteps. You stumble!" << endl;
                    cout << "No damage, and you're wide open!" << endl;
                }
                else {
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nHEAVY STRIKE for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                    cout << "But the follow-through leaves you exposed..." << endl;
                }
                player_open = true;
            }
            else if (action == "3") {
                int dmg = rand() % (base_max - base_min + 1) + base_min;
                int hit = rand() % 100 + 1;
                if (hit <= 25) {
                    int stumble = rand() % 8 + 5;
                    player_hp -= stumble;
                    cout << "\nYou overextend! The ogre shoves you down." << endl;
                    cout << stumble << " fall damage! Your HP: " << player_hp << endl;
                    player_open = true;
                }
                else if (hit >= 70) {
                    dmg = dmg * 2 + 5;
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nPerfect lunge! MASSIVE HIT for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                }
                else {
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nLunge connects! " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }
            else if (action == "4") {
                ogre_taunted = true;
                cout << "\nYou raise your sword and let out a warrior's roar!" << endl;
                cout << "The ogre flinches. It'll be off balance next round." << endl;
            }
            else { cout << "\nYou hesitate and waste the round!" << endl; }
        }

        // ============================
        // LANCE ACTIONS
        // ============================
        else if (weapon_name == "Lance") {
            if (action == "1") {
                int dmg = rand() % (base_max - base_min + 1) + base_min;
                int hit = rand() % 100 + 1;
                if (hit <= 15) {
                    cout << "\nYour jab pokes air. The ogre steps inside your range!" << endl;
                }
                else {
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nJab for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }
            else if (action == "2") {
                int dmg = rand() % (base_max - base_min + 1) + base_min + 5;
                ogre_hp -= dmg; damage_dealt = dmg;
                cout << "\nYou plant your feet and drive the lance forward." << endl;
                cout << "Guaranteed hit for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                cout << "But you're rooted -- no dodging this round." << endl;
                player_open = true;
            }
            else if (action == "3") {
                int dmg = rand() % 6 + 4;
                ogre_hp -= dmg; damage_dealt = dmg;
                ogre_slowed = true;
                cout << "\nYou SHOVE the ogre back! " << dmg << " damage, it stumbles! Ogre HP: " << ogre_hp << endl;
            }
            else if (action == "4") {
                int roll = rand() % 100 + 1;
                if (roll <= 30) {
                    player_hp -= 8;
                    cout << "\nThe lance handle smacks YOU in the face. 8 self-damage. Your HP: " << player_hp << endl;
                }
                else if (roll <= 70) {
                    int dmg = rand() % 15 + 12;
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nSpin clips the ogre! " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                }
                else {
                    int dmg = base_max + 15;
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nFULL SPIN CONNECTS! MASSIVE " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }
            else { cout << "\nYou hesitate and waste the round!" << endl; }
        }

        // ============================
        // BOW ACTIONS
        // ============================
        else if (weapon_name == "Bow") {
            if (action == "1") {
                int dmg = rand() % (base_max - base_min + 1) + base_min;
                if (aimed_shot_ready) {
                    dmg += rand() % 15 + 10;
                    aimed_shot_ready = false;
                    cout << "\nYou release the perfectly-aimed shot!" << endl;
                }
                else {
                    cout << "\nQuick nock and fire!" << endl;
                }
                ogre_hp -= dmg; damage_dealt = dmg;
                cout << "Hit for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (action == "2") {
                aimed_shot_ready = true;
                cout << "\nYou slow your breathing and draw back carefully..." << endl;
                cout << "Next shot will hit MUCH harder!" << endl;
            }
            else if (action == "3") {
                int dmg = rand() % (base_max - base_min + 1) + base_min + 4;
                aimed_shot_ready = false;
                ogre_hp -= dmg; damage_dealt = dmg;
                cout << "\nScatter Shot! " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (action == "4") {
                int dmg = rand() % 6 + 4;
                player_dodging = true; aimed_shot_ready = false;
                ogre_hp -= dmg; damage_dealt = dmg;
                cout << "\nDive and fire! " << dmg << " damage, dodge successful! Ogre HP: " << ogre_hp << endl;
            }
            else { cout << "\nYou hesitate and waste the round!" << endl; }
        }

        // ============================
        // SHIELD ACTIONS
        // ============================
        else if (weapon_name == "Shield") {
            if (action == "1") {
                int dmg = rand() % (base_max - base_min + 1) + base_min;
                ogre_hp -= dmg; damage_dealt = dmg;
                counter_ready = false;
                cout << "\nShield Bash for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (action == "2") {
                player_dodging = true;
                counter_ready  = true;
                cout << "\nBRACED! You absorb all damage and load up a counter!" << endl;
            }
            else if (action == "3") {
                if (counter_ready) {
                    int dmg = rand() % 20 + 20;
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nCOUNTER STRIKE for " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
                    counter_ready = false;
                }
                else {
                    int dmg = rand() % 4 + 2;
                    ogre_hp -= dmg; damage_dealt = dmg;
                    cout << "\nNo brace behind it -- weak hit for " << dmg << " damage. Use Brace first! Ogre HP: " << ogre_hp << endl;
                }
            }
            else if (action == "4") {
                ogre_taunted  = true;
                counter_ready = false;
                cout << "\nYou taunt the ogre! It'll swing recklessly next round." << endl;
            }
            else { cout << "\nYou hesitate and waste the round!" << endl; }
        }

        // ============================
        // BARE FISTS
        // ============================
        else {
            if (action == "1") {
                int dmg = rand() % (base_max - base_min + 1) + base_min;
                ogre_hp -= dmg; damage_dealt = dmg;
                cout << "\nYou throw a punch! " << dmg << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (action == "2") {
                int roll = rand() % 3;
                if      (roll == 0) { ogre_hp -= 12; damage_dealt = 12; cout << "\nHeadbutt to the knee! 12 damage! Ogre HP: " << ogre_hp << endl; }
                else if (roll == 1) { cout << "\nYou flail and miss. The ogre looks confused." << endl; }
                else                { player_hp -= 5; cout << "\nYou trip. 5 self-damage. Your HP: " << player_hp << endl; }
            }
            else if (action == "3") { player_dodging = true; cout << "\nYou tuck and roll!" << endl; }
            else                    { ogre_taunted = true;   cout << "\nYou scream. The ogre tilts its head." << endl; }
        }

        // ============================
        // MOMENTUM UPDATE
        // ============================
        if (damage_dealt > 0 && !surge_available) {
            momentum++;
            if (momentum >= 3) {
                momentum        = 3;
                surge_available = true;
                cout << "  [MOMENTUM MAXED -- SURGE ready! Use option 5!]" << endl;
            }
        }

        if (ogre_hp <= 0) break;

        // ============================
        // OGRE'S TURN
        // ============================
        cout << endl;
        if (player_dodging) {
            cout << "The ogre swings -- but you're not there! Complete dodge!" << endl;
        }
        else {
            int ogre_roll      = rand() % 100 + 1;
            int miss_threshold = 15;
            if (ogre_taunted) miss_threshold += 30;
            if (ogre_slowed)  miss_threshold += 20;

            if (ogre_roll <= miss_threshold) {
                cout << "The ogre swings wildly and misses!" << endl;
            }
            else if (ogre_roll >= 92) {
                int ogre_damage = ogre_max + 10;
                if (player_open) ogre_damage += 8;
                if (enraged)     ogre_damage += 5;
                cout << "The ogre CRUSHES you";
                if (player_open) cout << ", exploiting your opening";
                cout << "! " << ogre_damage << " damage! Your HP: ";
                player_hp -= ogre_damage;
                cout << player_hp << endl;
                if (ogre_damage >= 15) {
                    momentum = 0; surge_available = false;
                    cout << "  [MOMENTUM BROKEN!]" << endl;
                }
            }
            else {
                int ogre_damage = rand() % (ogre_max - ogre_min + 1) + ogre_min;
                if (player_open) ogre_damage += 6;
                if (enraged)     ogre_damage += 3;
                if (ogre_damage < 1) ogre_damage = 1;
                player_hp -= ogre_damage;
                cout << "The ogre hits you";
                if (player_open) cout << " (harder -- you were exposed)";
                cout << " for " << ogre_damage << " damage! Your HP: " << player_hp << endl;
                if (ogre_damage >= 15) {
                    momentum = 0; surge_available = false;
                    cout << "  [MOMENTUM BROKEN!]" << endl;
                }
            }
        }

        ogre_taunted = false;
        ogre_slowed  = false;
        player_open  = false;

        // ============================
        // RANDOM EVENTS (every 4 rounds)
        // ============================
        if (round % 4 == 0 && player_hp > 0 && ogre_hp > 0) {
            int event = rand() % 5;
            cout << "\n  ** RANDOM EVENT **" << endl;
            if (event == 0) {
                ogre_hp -= 15;
                cout << "  A stalactite cracks the ogre on the head! (-15 HP) Ogre HP: " << ogre_hp << endl;
            }
            else if (event == 1) {
                player_hp += 20;
                if (player_hp > 100) player_hp = 100;
                cout << "  You find a health vial! (+20 HP) Your HP: " << player_hp << endl;
            }
            else if (event == 2) {
                player_hp -= 8;
                if (momentum > 0) momentum--;
                cout << "  The ogre roars! You flinch. (-8 HP) Your HP: " << player_hp << endl;
            }
            else if (event == 3) {
                cout << "  The torches flicker. You both freeze... then continue." << endl;
            }
            else {
                if (momentum < 3) {
                    momentum++;
                    if (momentum >= 3) { surge_available = true; cout << "  You spot a weak point! [SURGE READY!]" << endl; }
                    else cout << "  You spot a weak point! Momentum up." << endl;
                }
            }
        }

        round++;
    }

    // ============================
    // RESULT
    // ============================
    cout << "\n========================================" << endl;
    if (ogre_hp <= 0 && player_hp > 0) {
        ending_victory(player_hp);
        player_wins++;
    }
    else {
        ending_defeat();
        player_losses++;
    }
    cout << "========================================" << endl;
}

// =============================================
// ENDINGS
// =============================================

void ending_victory(int player_hp) {
    cout << "The ogre crashes to the ground with a final groan!" << endl;
    if (player_hp >= 75) {
        cout << "You're barely scratched. DOMINANT VICTORY!" << endl;
        cout << "The Goddess applauds. \"That barely looked like a fight.\"" << endl;
    }
    else if (player_hp >= 40) {
        cout << "Wounded but standing. HARD FOUGHT VICTORY!" << endl;
        cout << "The Goddess nods. \"I knew I picked the right hero.\"" << endl;
    }
    else {
        cout << "You drop to one knee after the final blow." << endl;
        cout << "SURVIVED BY THE SKIN OF YOUR TEETH!" << endl;
        cout << "The Goddess winces. \"...That was close. Too close.\"" << endl;
    }
}

void ending_defeat() {
    cout << "You collapse. The ogre stands over you." << endl;
    cout << "The Goddess pulls you back just in time..." << endl;
    cout << "DEFEAT. Better luck next time, hero." << endl;
}

#endif