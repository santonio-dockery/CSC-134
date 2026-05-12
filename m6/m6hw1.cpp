/*
 * CSC 134 - M6HW1: Project Prototype
 * LOCK-AND-KEY EXPLANATION:
 *  The Archers won't fire the signal volley until you've retrieved the
 *  Enemy Map from the Cave. Once you have the map, return to Archer's
 *  Point and interact — they fire, the enemy retreats, you win.
 */

#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// CONSTANTS
// -------------------------------------------------------
enum Room {
    ENCAMPMENT  = 0,
    MEDICAL     = 1,
    ARCHERS     = 2,
    CAVE        = 3,
    TRENCH      = 4,
    MY_QUARTERS = 5,
    NUM_ROOMS   = 6
};

enum Direction {
    NORTH          = 0,
    EAST           = 1,
    SOUTH          = 2,
    WEST           = 3,
    NORTHEAST      = 4,
    NORTHWEST      = 5,
    NUM_DIRECTIONS = 6
};

const int NO_CONNECTION = -1;

// -------------------------------------------------------
// GAME STATE  (global so every function can read/write it)
// -------------------------------------------------------
bool hasEnemyMap   = false;   // picked up in the Cave
bool hasRations    = false;   // picked up in My Quarters
bool mapUsed       = false;   // given to the Archers
bool gameOver      = false;   // set true when the player wins or dies

// -------------------------------------------------------
// FUNCTION PROTOTYPES
// -------------------------------------------------------
void printRoom(string roomNames[], string roomDescriptions[], int room);
void printExits(int connections[][NUM_DIRECTIONS], int room);
void printInventory();
int  commandToDirection(const string& command);
void handleInteraction(int room);
void printIntro();

// -------------------------------------------------------
// MAIN
// -------------------------------------------------------
int main()
{
    // ------ Room names ------
    string roomNames[NUM_ROOMS] = {
        "Main Encampment",   // 0
        "Medical Center",    // 1
        "Archer's Point",    // 2
        "Mysterious Cave",   // 3
        "Trench",            // 4
        "My Quarters"        // 5
    };

    // ------ Room descriptions ------
    string roomDescriptions[NUM_ROOMS] = {
        "The heart of the army. Tents stretch to the horizon. The General's\n"
        "command post sits in the center, maps pinned to every surface.",

        "The medical tent reeks of blood and ether. Nurses move quickly\n"
        "between rows of cots. A surgeon waves you toward an empty chair.",

        "Archer's Point overlooks the valley. Dozens of bowmen stand ready,\n"
        "arrows nocked, waiting for the order. The sergeant eyes you expectantly.",

        "A narrow cave cuts into the hillside. The air smells of damp stone.\n"
        "Old supply crates line the walls — the previous unit left in a hurry.",

        "The trench is chaos. Mud, noise, and the crack of enemy rifles.\n"
        "Soldiers keep their heads low. Every second counts here.",

        "Your quarters: a canvas cot, a rusted footlocker, and a lantern\n"
        "burning low. A half-eaten ration pack sits on the lid of the locker."
    };

    // ------ Adjacency table ------
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    for (int room = 0; room < NUM_ROOMS; room++)
        for (int dir  = 0; dir  < NUM_DIRECTIONS; dir++)
            connections[room][dir] = NO_CONNECTION;

    // Encampment is the central hub
    connections[ENCAMPMENT][NORTH]     = MEDICAL;
    connections[ENCAMPMENT][EAST]      = ARCHERS;
    connections[ENCAMPMENT][SOUTH]     = TRENCH;
    connections[ENCAMPMENT][WEST]      = CAVE;
    connections[ENCAMPMENT][NORTHEAST] = MY_QUARTERS;

    // Return paths
    connections[MEDICAL][SOUTH]          = ENCAMPMENT;
    connections[ARCHERS][WEST]           = ENCAMPMENT;
    connections[TRENCH][NORTH]           = ENCAMPMENT;
    connections[CAVE][EAST]              = ENCAMPMENT;
    connections[MY_QUARTERS][NORTHWEST]  = ENCAMPMENT;

    // ------ Game start ------
    printIntro();

    int    currentRoom = ENCAMPMENT;
    string command;

    cout << "Commands: north/n  east/e  south/s  west/w  northeast/ne  northwest/nw\n";
    cout << "          look     interact/i     inventory/inv     quit\n" << endl;

    printRoom(roomNames, roomDescriptions, currentRoom);
    printExits(connections, currentRoom);

    // ------ Main loop ------
    while (!gameOver)
    {
        cout << "\n> ";
        cin  >> command;

        if (command == "quit")
        {
            cout << "\nYou drop your rifle and walk away from the war.\n";
            cout << "Some battles aren't worth fighting. Game over.\n";
            break;
        }
        else if (command == "look")
        {
            printRoom(roomNames, roomDescriptions, currentRoom);
            printExits(connections, currentRoom);
        }
        else if (command == "inventory" || command == "inv")
        {
            printInventory();
        }
        else if (command == "interact" || command == "i")
        {
            handleInteraction(currentRoom);

            // After every interaction, re-print exits if still playing
            if (!gameOver)
                printExits(connections, currentRoom);
        }
        else
        {
            int direction = commandToDirection(command);

            if (direction == -1)
            {
                cout << "Unknown command. Try: north, east, south, west, "
                     << "northeast, northwest, look, interact, inventory, quit." << endl;
            }
            else
            {
                int nextRoom = connections[currentRoom][direction];

                if (nextRoom == NO_CONNECTION)
                {
                    cout << "A wall of sandbags and coiled wire blocks your path." << endl;
                }
                else
                {
                    currentRoom = nextRoom;
                    printRoom(roomNames, roomDescriptions, currentRoom);
                    printExits(connections, currentRoom);
                }
            }
        }
    }

    cout << "\nThanks for playing WAR ZONE." << endl;
    return 0;
}

// -------------------------------------------------------
// INTRO — explains the point of the game (Silver req.)
// -------------------------------------------------------
void printIntro()
{
    cout << "========================================================\n";
    cout << "                 WAR ZONE: TEXT ADVENTURE               \n";
    cout << "========================================================\n\n";
    cout << "MISSION BRIEFING:\n";
    cout << "The enemy is massing for a dawn assault. Intelligence\n";
    cout << "believes they left a copy of their attack map in a cave\n";
    cout << "west of camp. Recover the map, bring it to Archer's\n";
    cout << "Point, and our archers can use it to signal a pre-emptive\n";
    cout << "volley that will break their advance before it begins.\n\n";
    cout << "Fail, and by morning there may be no camp left.\n\n";
    cout << "  YOUR GOAL: Find the Enemy Map -> Bring it to the Archers\n";
    cout << "========================================================\n\n";
}

// -------------------------------------------------------
// PRINT ROOM
// -------------------------------------------------------
void printRoom(string roomNames[], string roomDescriptions[], int room)
{
    cout << "\n--- " << roomNames[room] << " ---\n";
    cout << roomDescriptions[room] << "\n";
}

// -------------------------------------------------------
// PRINT EXITS
// -------------------------------------------------------
void printExits(int connections[][NUM_DIRECTIONS], int room)
{
    const string dirNames[NUM_DIRECTIONS] = {
        "north", "east", "south", "west", "northeast", "northwest"
    };
    cout << "Exits: ";
    bool any = false;
    for (int d = 0; d < NUM_DIRECTIONS; d++)
    {
        if (connections[room][d] != NO_CONNECTION)
        {
            if (any) cout << ", ";
            cout << dirNames[d];
            any = true;
        }
    }
    if (!any) cout << "(none)";
    cout << "\n";
}

// -------------------------------------------------------
// PRINT INVENTORY
// -------------------------------------------------------
void printInventory()
{
    cout << "\n-- Inventory --\n";
    bool empty = true;
    if (hasEnemyMap)  { cout << "  * Enemy Attack Map (needs to reach Archer's Point!)\n"; empty = false; }
    if (hasRations)   { cout << "  * Field Rations\n"; empty = false; }
    if (empty)          cout << "  (nothing)\n";
}

// -------------------------------------------------------
// INTERACTIONS  — Silver dialog + item pickups
//                 Gold lock-and-key at ARCHERS
// -------------------------------------------------------
void handleInteraction(int room)
{
    switch (room)
    {
        // ── ENCAMPMENT: General gives briefing ──────────────────
        case ENCAMPMENT:
            cout << "\nThe General looks up from his maps, jaw tight.\n";
            cout << "\"Listen carefully. There's a cave to the west — the\n";
            cout << " scouts say the enemy cached their attack plans there.\n";
            cout << " Retrieve that map and get it to our archers. MOVE.\"\n";
            if (hasEnemyMap && !mapUsed)
                cout << "\n(You're already carrying the map. Head east to Archer's Point!)\n";
            break;

        // ── MEDICAL: heal up, grab some flavor ──────────────────
        case MEDICAL:
            cout << "\nThe surgeon looks you over quickly.\n";
            cout << "\"You're still in one piece — barely. Rest a moment.\"\n";
            cout << "She re-tapes your bandages. You feel steadier.\n";
            cout << "(HP restored — you're good to keep going.)\n";
            break;

        // ── ARCHERS: THE LOCK-AND-KEY ────────────────────────────
        // Key  = Enemy Map (picked up in Cave)
        // Lock = Sergeant won't fire signal volley without it
        case ARCHERS:
            if (!hasEnemyMap)
            {
                // LOCKED — player doesn't have the key item yet
                cout << "\nThe sergeant shakes his head.\n";
                cout << "\"I need their positions before I can fire a precision\n";
                cout << " volley, sir. Without that map we'd be shooting blind.\n";
                cout << " Find their plans and bring them here.\"\n";
            }
            else if (hasEnemyMap && !mapUsed)
            {
                // UNLOCKED — player delivers the key item → WIN
                cout << "\nYou thrust the Enemy Map into the sergeant's hands.\n";
                cout << "His eyes scan the page, widening.\n";
                cout << "\"This is it — their entire attack grid. ARCHERS, READY!\"\n\n";
                cout << "A hundred bowstrings draw back. On his signal, a volley\n";
                cout << "of arrows darkens the sky. Screams rise from the valley.\n\n";
                cout << "The enemy assault collapses before it ever began.\n";
                cout << "By dawn, they are in full retreat.\n\n";
                cout << "The General finds you in the trench and clasps your hand.\n";
                cout << "\"You saved them all, soldier. Well done.\"\n\n";
                cout << "========================================================\n";
                cout << "                     ** YOU WIN **                       \n";
                cout << "========================================================\n";
                mapUsed  = true;
                gameOver = true;
            }
            break;

        // ── CAVE: item pickup (the KEY item) ────────────────────
        case CAVE:
            if (!hasEnemyMap)
            {
                cout << "\nYou rummage through the dusty supply crates.\n";
                cout << "Behind a rotting sack of grain you find a leather satchel.\n";
                cout << "Inside: a folded document stamped with enemy insignia.\n\n";
                cout << "You unfold it — it's their complete attack map,\n";
                cout << "showing every approach route and artillery position.\n\n";
                cout << "*** You picked up the Enemy Attack Map! ***\n";
                cout << "Get this to the archers at Archer's Point (east of camp)!\n";
                hasEnemyMap = true;
            }
            else
            {
                cout << "\nYou've already taken the map. The cave has nothing left.\n";
                cout << "A rat stares at you from atop an empty crate.\n";
            }
            break;

        // ── TRENCH: atmosphere + hint ───────────────────────────
        case TRENCH:
            cout << "\nYou crouch low as bullets crack overhead.\n";
            cout << "A corporal grabs your sleeve.\n";
            cout << "\"Sir! They're massing to the east. If our archers don't\n";
            cout << " break them before dawn, we're finished. Please hurry.\"\n";
            if (!hasEnemyMap)
                cout << "\n(Hint: The cave to the west of camp might have something useful.)\n";
            else
                cout << "\n(You have the map! Get to Archer's Point — go north, then east.)\n";
            break;

        // ── MY QUARTERS: second item pickup (optional, flavor) ──
        case MY_QUARTERS:
            if (!hasRations)
            {
                cout << "\nYou flip open the footlocker. Inside, past old letters home,\n";
                cout << "you find a sealed ration pack — still good.\n";
                cout << "You pocket it. Never know when you'll need it.\n";
                cout << "*** You picked up Field Rations! ***\n";
                hasRations = true;
            }
            else
            {
                cout << "\nThe footlocker is empty now. The cot looks tempting,\n";
                cout << "but there's a war outside.\n";
            }
            break;

        default:
            cout << "Nothing to interact with here.\n";
            break;
    }
}

// -------------------------------------------------------
// COMMAND → DIRECTION
// -------------------------------------------------------
int commandToDirection(const string& command)
{
    if (command == "north"     || command == "n")  return NORTH;
    if (command == "east"      || command == "e")  return EAST;
    if (command == "south"     || command == "s")  return SOUTH;
    if (command == "west"      || command == "w")  return WEST;
    if (command == "northeast" || command == "ne") return NORTHEAST;
    if (command == "northwest" || command == "nw") return NORTHWEST;
    return -1;
}