// M3LAB1
// norrisa
// 2/23/26

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Prototypes
void picksword();
void picklance();
void pickshield();
void pickbow();
void start_battle(int base_min, int base_max);

// Global Data
string weapon_name;
int weapon_strength;
int wins = 0;
int losses = 0;
int games_played = 0;

int main() {
    srand(time(0));

    string choice;
    string play_again = "yes";

    cout << "========================================" << endl;
    cout << "         THE HERO'S JOURNEY             " << endl;
    cout << "========================================" << endl;
    cout << "You're going about your day when suddenly" << endl;
    cout << "you're whisked into another world!" << endl;
    cout << "A Goddess appears and says YOU are the hero." << endl;

    while (play_again == "yes") {

        weapon_name = "";
        weapon_strength = 0;
        games_played++;

        cout << "\n--- Game " << games_played << " ---" << endl;
        cout << "The Goddess offers you a weapon. Choose wisely!" << endl;
        cout << "1. Sword  - High damage, aggressive options" << endl;
        cout << "2. Lance  - Range control, keep the ogre at bay" << endl;
        cout << "3. Bow    - Tactical setup, hit hard from a distance" << endl;
        cout << "4. Shield - Outlast and punish, turn defense into offense" << endl;
        cout << "> ";
        cin >> choice;

        if      (choice == "1") { picksword(); }
        else if (choice == "2") { picklance(); }
        else if (choice == "3") { pickbow();   }
        else if (choice == "4") { pickshield();}
        else {
            cout << "You froze up. The Goddess sends you with bare fists!" << endl;
            weapon_name = "Bare Fists";
            weapon_strength = 2;
            start_battle(2, 6);
        }

        cout << "\n----------------------------------------" << endl;
        cout << "Stats -> Wins: " << wins << " | Losses: " << losses << " | Games: " << games_played << endl;
        cout << "----------------------------------------" << endl;
        cout << "Play again? (yes/no): ";
        cin >> play_again;
    }

    cout << "\n========================================" << endl;
    cout << "            FINAL RESULTS               " << endl;
    cout << "========================================" << endl;
    cout << "Games Played : " << games_played << endl;
    cout << "Wins         : " << wins << endl;
    cout << "Losses       : " << losses << endl;

    if (wins > losses) {
        cout << "The Goddess smiles. You were a true hero!" << endl;
    }
    else if (losses > wins) {
        cout << "The Goddess shakes her head. Keep training, hero." << endl;
    }
    else {
        cout << "The Goddess nods. A balanced hero. Not bad." << endl;
    }

    cout << "Thanks for playing The Hero's Journey!" << endl;
    return 0;
}

// ==================
// WEAPON FUNCTIONS
// ==================

void picksword() {
    cout << "\nYou grab the Sword. It hums with power in your grip." << endl;
    cout << "You are teleported to an ogre's den!" << endl;
    weapon_name = "Sword";
    weapon_strength = 20;
    start_battle(15, 30);
}

void picklance() {
    cout << "\nYou grab the Lance. It's longer than you expected." << endl;
    cout << "You are teleported to an ogre's den!" << endl;
    weapon_name = "Lance";
    weapon_strength = 10;
    start_battle(10, 20);
}

void pickbow() {
    cout << "\nYou grab the Bow and a quiver of arrows." << endl;
    cout << "You are teleported to an ogre's den!" << endl;
    weapon_name = "Bow";
    weapon_strength = 5;
    start_battle(6, 14);
}

void pickshield() {
    cout << "\nYou grab the Shield. It's heavier than it looks." << endl;
    cout << "You are teleported to an ogre's den!" << endl;
    weapon_name = "Shield";
    weapon_strength = 1;
    start_battle(3, 8);
}

// ==================
// BATTLE FUNCTION
// ==================

void start_battle(int base_min, int base_max) {
    int player_hp = 100;
    int ogre_hp   = 150;
    int round     = 1;
    string action;

    // Status flags that carry between rounds
    bool player_open       = false;  // Heavy Strike left you exposed
    bool ogre_taunted      = false;  // Ogre will swing wild this round
    bool player_dodging    = false;  // Dodge cancels all ogre damage
    bool ogre_slowed       = false;  // Lance shove: ogre misses more this round
    bool aimed_shot_ready  = false;  // Bow: Aim last round, big hit this round
    bool counter_ready     = false;  // Shield: Brace last round, counter this round

    int ogre_min = 8;
    int ogre_max = 18;

    cout << "\n========================================" << endl;
    cout << "  A massive ogre blocks your path!" << endl;
    cout << "  Your weapon: " << weapon_name << endl;
    cout << "  Your HP: " << player_hp << " | Ogre HP: " << ogre_hp << endl;
    cout << "========================================" << endl;

    while (player_hp > 0 && ogre_hp > 0) {

        cout << "\n--- Round " << round << " ---" << endl;
        cout << "Your HP: " << player_hp << " | Ogre HP: " << ogre_hp << endl;
        cout << "\nWhat do you do?" << endl;

        // ---- SHOW WEAPON-SPECIFIC OPTIONS ----

        if (weapon_name == "Sword") {
            cout << "1. Slash        - Standard strike, balanced risk" << endl;
            cout << "2. Heavy Strike - Massive damage, but you're wide open after" << endl;
            cout << "3. Lunge        - Risky dash forward, high crit chance, might miss badly" << endl;
            cout << "4. Intimidate   - No damage, but ogre hesitates next round (misses more)" << endl;
        }
        else if (weapon_name == "Lance") {
            cout << "1. Jab          - Quick poke from a safe distance" << endl;
            cout << "2. Brace & Thrust - Plant your feet, guaranteed hit but no dodge possible" << endl;
            cout << "3. Shove        - Push the ogre back, deal small damage, ogre misses next round" << endl;
            cout << "4. Spin Strike  - Wild spinning attack, random outcome, could be huge or nothing" << endl;
        }
        else if (weapon_name == "Bow") {
            cout << "1. Quick Shot   - Fast arrow, lower damage but always fires" << endl;
            cout << "2. Aim          - Skip damage this round, next shot hits much harder" << endl;
            cout << "3. Scatter Shot - Fire multiple arrows, hits for sure but lower per-arrow damage" << endl;
            cout << "4. Roll Back    - Dive away and fire, avoid ogre damage, small damage on the shot" << endl;
        }
        else if (weapon_name == "Shield") {
            cout << "1. Bash         - Ram the shield into the ogre, low but reliable damage" << endl;
            cout << "2. Brace        - Block this round, take no damage, set up a counter next round" << endl;
            cout << "3. Counter      - Only works after Brace! Explosive counter-attack" << endl;
            cout << "4. Taunt        - Provoke the ogre into wild swings, easier to dodge next round" << endl;
        }
        else {
            // Bare fists fallback
            cout << "1. Punch        - Just throw a punch" << endl;
            cout << "2. Flail        - Swing wildly, random result" << endl;
            cout << "3. Duck         - Dodge everything this round" << endl;
            cout << "4. Yell         - Distract the ogre, it misses next round" << endl;
        }

        cout << "> ";
        cin >> action;

        // Reset per-round flags
        player_dodging = false;
        player_open    = false;

        // ============================
        // SWORD ACTIONS
        // ============================
        if (weapon_name == "Sword") {

            if (action == "1") {
                // Slash — standard
                int damage   = rand() % (base_max - base_min + 1) + base_min;
                int hit_roll = rand() % 100 + 1;
                if (hit_roll <= 10) {
                    cout << "\nYou slash but the ogre deflects it with its arm. No damage." << endl;
                }
                else if (hit_roll >= 88) {
                    damage *= 2;
                    ogre_hp -= damage;
                    cout << "\nCRITICAL! Your sword finds a gap in the ogre's hide!" << endl;
                    cout << "You deal " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                }
                else {
                    ogre_hp -= damage;
                    cout << "\nClean slash for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }

            else if (action == "2") {
                // Heavy Strike — big damage, left open
                int damage   = rand() % (base_max - base_min + 1) + base_min + 12;
                int hit_roll = rand() % 100 + 1;
                if (hit_roll <= 20) {
                    cout << "\nYou wind up for everything... and the ogre sidesteps. You stumble!" << endl;
                    cout << "No damage, and you're wide open!" << endl;
                }
                else {
                    ogre_hp -= damage;
                    cout << "\nYou put your whole body into it!" << endl;
                    cout << "HEAVY STRIKE for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                    cout << "But the follow-through leaves you off balance..." << endl;
                }
                player_open = true;
            }

            else if (action == "3") {
                // Lunge — high crit, high miss
                int damage   = rand() % (base_max - base_min + 1) + base_min;
                int hit_roll = rand() % 100 + 1;
                if (hit_roll <= 25) {
                    cout << "\nYou lunge forward and completely overextend! The ogre shoves you down." << endl;
                    int stumble = rand() % 8 + 5;
                    player_hp -= stumble;
                    cout << "You take " << stumble << " fall damage! Your HP: " << player_hp << endl;
                    player_open = true;
                }
                else if (hit_roll >= 70) {
                    damage = damage * 2 + 5;
                    ogre_hp -= damage;
                    cout << "\nPerfect lunge! Sword drives straight through!" << endl;
                    cout << "MASSIVE HIT for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                }
                else {
                    ogre_hp -= damage;
                    cout << "\nYou lunge and connect! " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }

            else if (action == "4") {
                // Intimidate — ogre misses more next round
                ogre_taunted = true;
                cout << "\nYou raise your sword and let out a warrior's roar!" << endl;
                cout << "The ogre flinches. It'll be off balance next round." << endl;
            }

            else {
                cout << "\nYou hesitate and waste the round!" << endl;
            }
        }

        // ============================
        // LANCE ACTIONS
        // ============================
        else if (weapon_name == "Lance") {

            if (action == "1") {
                // Jab — quick, safe, lower damage
                int damage   = rand() % 10 + base_min;
                int hit_roll = rand() % 100 + 1;
                if (hit_roll <= 15) {
                    cout << "\nYour jab pokes air. The ogre steps inside your range!" << endl;
                }
                else {
                    ogre_hp -= damage;
                    cout << "\nYou keep your distance and jab for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }

            else if (action == "2") {
                // Brace & Thrust — guaranteed hit, can't dodge
                int damage = rand() % (base_max - base_min + 1) + base_min + 5;
                ogre_hp -= damage;
                cout << "\nYou plant your feet and drive the lance forward." << endl;
                cout << "Guaranteed hit for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                cout << "But you're rooted in place — no dodging the ogre's swing." << endl;
                player_open = true;
            }

            else if (action == "3") {
                // Shove — small damage, ogre slowed next round
                int damage = rand() % 6 + 4;
                ogre_hp   -= damage;
                ogre_slowed = true;
                cout << "\nYou drive the lance shaft into the ogre's chest and PUSH!" << endl;
                cout << "The ogre stumbles back " << damage << " damage dealt! Ogre HP: " << ogre_hp << endl;
                cout << "It's off balance — it'll have trouble aiming next round!" << endl;
            }

            else if (action == "4") {
                // Spin Strike — random, could be great or terrible
                int spin_roll = rand() % 100 + 1;
                if (spin_roll <= 30) {
                    cout << "\nYou spin wildly... and the lance handle smacks you in the face." << endl;
                    player_hp -= 8;
                    cout << "Self-inflicted 8 damage. Embarrassing. Your HP: " << player_hp << endl;
                }
                else if (spin_roll <= 70) {
                    int damage = rand() % 15 + 10;
                    ogre_hp -= damage;
                    cout << "\nThe spinning lance clips the ogre from an unexpected angle!" << endl;
                    cout << damage << " damage! Ogre HP: " << ogre_hp << endl;
                }
                else {
                    int damage = base_max + 15;
                    ogre_hp -= damage;
                    cout << "\nFULL SPIN CONNECTS! The lance sweeps the ogre's legs and cracks its ribs!" << endl;
                    cout << "MASSIVE " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                }
            }

            else {
                cout << "\nYou hesitate and waste the round!" << endl;
            }
        }

        // ============================
        // BOW ACTIONS
        // ============================
        else if (weapon_name == "Bow") {

            if (action == "1") {
                // Quick Shot — always fires, lower damage
                int damage = rand() % 8 + base_min;
                ogre_hp -= damage;
                cout << "\nYou nock and fire in one fluid motion!" << endl;
                cout << "Quick Shot hits for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                aimed_shot_ready = false;
            }

            else if (action == "2") {
                // Aim — skip this round, next shot is much bigger
                aimed_shot_ready = true;
                cout << "\nYou slow your breathing and draw back carefully..." << endl;
                cout << "You're taking aim. Your next shot will hit much harder!" << endl;
            }

            else if (action == "3") {
                // Scatter Shot — guaranteed hit, moderate damage
                int damage = rand() % 10 + base_min + 4;
                ogre_hp -= damage;
                cout << "\nYou fire a spread of arrows — the ogre can't dodge all of them!" << endl;
                cout << "Scatter Shot hits for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                aimed_shot_ready = false;
            }

            else if (action == "4") {
                // Roll Back — dodge + small shot
                int damage = rand() % 6 + 3;
                player_dodging = true;
                ogre_hp -= damage;
                cout << "\nYou dive sideways and fire mid-roll!" << endl;
                cout << "Small hit for " << damage << " damage, and you dodge the ogre's swing! Ogre HP: " << ogre_hp << endl;
                aimed_shot_ready = false;
            }

            else {
                cout << "\nYou hesitate and waste the round!" << endl;
            }
        }

        // ============================
        // SHIELD ACTIONS
        // ============================
        else if (weapon_name == "Shield") {

            if (action == "1") {
                // Bash — reliable low damage
                int damage = rand() % (base_max - base_min + 1) + base_min;
                ogre_hp -= damage;
                cout << "\nYou charge forward and SLAM the shield into the ogre!" << endl;
                cout << "Shield Bash for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                counter_ready = false;
            }

            else if (action == "2") {
                // Brace — block all damage, set up counter
                player_dodging = true;
                counter_ready  = true;
                cout << "\nYou plant your feet and raise the shield!" << endl;
                cout << "BRACED! You absorb all damage this round." << endl;
                cout << "The ogre's impact loads your arm — you're ready to counter!" << endl;
            }

            else if (action == "3") {
                // Counter — only works after Brace
                if (counter_ready) {
                    int damage = rand() % 20 + 18;  // 18-37, strong payoff
                    ogre_hp -= damage;
                    cout << "\nYou release all that stored energy in one explosive counter!" << endl;
                    cout << "COUNTER STRIKE for " << damage << " damage! Ogre HP: " << ogre_hp << endl;
                    counter_ready = false;
                }
                else {
                    cout << "\nYou swing a counter but you never braced — there's no power behind it!" << endl;
                    int damage = rand() % 4 + 2;
                    ogre_hp -= damage;
                    cout << "Weak hit for only " << damage << " damage. Use Brace first next time! Ogre HP: " << ogre_hp << endl;
                }
            }

            else if (action == "4") {
                // Taunt — ogre swings wild next round
                ogre_taunted  = true;
                counter_ready = false;
                cout << "\nYou bang your shield and shout at the ogre!" << endl;
                cout << "It's furious! It'll swing recklessly next round — easier to handle!" << endl;
            }

            else {
                cout << "\nYou hesitate and waste the round!" << endl;
            }
        }

        // ============================
        // BARE FISTS FALLBACK
        // ============================
        else {
            if (action == "1") {
                int damage = rand() % (base_max - base_min + 1) + base_min;
                ogre_hp -= damage;
                cout << "\nYou throw a punch! " << damage << " damage! Ogre HP: " << ogre_hp << endl;
            }
            else if (action == "2") {
                int flail_roll = rand() % 3;
                if (flail_roll == 0) {
                    cout << "\nYou flail wildly and somehow headbutt the ogre's knee." << endl;
                    ogre_hp -= 12;
                    cout << "12 damage?! Ogre HP: " << ogre_hp << endl;
                }
                else if (flail_roll == 1) {
                    cout << "\nYou flail and miss everything. The ogre looks confused." << endl;
                }
                else {
                    cout << "\nYou trip over your own feet." << endl;
                    player_hp -= 5;
                    cout << "5 self damage. Your HP: " << player_hp << endl;
                }
            }
            else if (action == "3") {
                player_dodging = true;
                cout << "\nYou tuck and roll out of the way!" << endl;
            }
            else {
                ogre_taunted = true;
                cout << "\nYou scream at the ogre. It tilts its head, confused." << endl;
            }
        }

        // Check if ogre died before it attacks
        if (ogre_hp <= 0) break;

        // ============================
        // OGRE'S TURN
        // ============================
        cout << endl;

        if (player_dodging) {
            cout << "The ogre swings — but you're not there! Complete dodge!" << endl;
        }
        else {
            int ogre_roll     = rand() % 100 + 1;
            int miss_threshold = 20;

            if (ogre_taunted)  miss_threshold += 30;  // taunt/intimidate makes ogre wild
            if (ogre_slowed)   miss_threshold += 20;  // shove makes ogre stumble

            if (ogre_roll <= miss_threshold) {
                cout << "The ogre swings wildly and completely misses!" << endl;
            }
            else if (ogre_roll >= 90) {
                int ogre_damage = ogre_max + 10;
                if (player_open) {
                    ogre_damage += 10;
                    cout << "The ogre EXPLOITS your opening and lands a crushing blow!" << endl;
                }
                else {
                    cout << "The ogre winds up and CRUSHES you with everything it has!" << endl;
                }
                player_hp -= ogre_damage;
                cout << "You take " << ogre_damage << " damage! Your HP: " << player_hp << endl;
            }
            else {
                int ogre_damage = rand() % (ogre_max - ogre_min + 1) + ogre_min;
                if (player_open) {
                    ogre_damage += 8;
                    cout << "The ogre sees you're off balance and hits harder!" << endl;
                }
                else {
                    cout << "The ogre swings at you!" << endl;
                }
                if (ogre_damage < 1) ogre_damage = 1;
                player_hp -= ogre_damage;
                cout << "You take " << ogre_damage << " damage! Your HP: " << player_hp << endl;
            }
        }

        // Reset carry-over flags after ogre's turn resolves
        ogre_taunted = false;
        ogre_slowed  = false;

        // Aimed shot activates NEXT player turn — check it via the flag already set above

        // Random event every 4 rounds
        if (round % 4 == 0 && player_hp > 0 && ogre_hp > 0) {
            int event = rand() % 4;
            cout << "\n  ** RANDOM EVENT **" << endl;
            if (event == 0) {
                cout << "  A stalactite falls and cracks the ogre on the head! (-15 HP)" << endl;
                ogre_hp -= 15;
                cout << "  Ogre HP: " << ogre_hp << endl;
            }
            else if (event == 1) {
                cout << "  You spot a health vial wedged between some rocks! (+20 HP)" << endl;
                player_hp += 20;
                if (player_hp > 100) player_hp = 100;
                cout << "  Your HP: " << player_hp << endl;
            }
            else if (event == 2) {
                cout << "  The ogre lets out a ground-shaking roar! You flinch. (-8 HP)" << endl;
                player_hp -= 8;
                cout << "  Your HP: " << player_hp << endl;
            }
            else {
                cout << "  The torches flicker. You both freeze for a moment... then continue." << endl;
            }
        }

        // Apply aimed shot bonus on the NEXT round's base damage
        // (already flagged — player sees the reminder at top of next round)
        if (aimed_shot_ready && weapon_name == "Bow") {
            cout << "\n  [You're still aimed in — your next shot will hit hard!]" << endl;
            base_min += 10;
            base_max += 15;
            aimed_shot_ready = false;  // consumed next round naturally via base stats
        }

        round++;
    }

    // ============================
    // FIGHT RESULT
    // ============================
    cout << "\n========================================" << endl;
    if (ogre_hp <= 0 && player_hp > 0) {
        cout << "The ogre crashes to the ground with a final groan!" << endl;
        if (player_hp >= 75) {
            cout << "You're barely scratched. DOMINANT VICTORY!" << endl;
        }
        else if (player_hp >= 40) {
            cout << "Wounded but standing. HARD FOUGHT VICTORY!" << endl;
        }
        else {
            cout << "You drop to one knee after the final blow." << endl;
            cout << "SURVIVED BY THE SKIN OF YOUR TEETH!" << endl;
        }
        wins++;
    }
    else {
        cout << "You collapse. The ogre stands over you." << endl;
        cout << "The Goddess pulls you back just in time..." << endl;
        cout << "DEFEAT. Better luck next time, hero." << endl;
        losses++;
    }
    cout << "========================================" << endl;
}