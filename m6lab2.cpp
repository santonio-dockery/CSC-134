#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// CONSTANTS
// -------------------------------------------------------
// These are "enum" values — they give human-readable names
// to index numbers so your code is readable.
// ENCAMPMENT = 0, MEDICAL = 1, ARCHERS = 2, CAVE = 3, TRENCH = 4
enum Room {
    ENCAMPMENT = 0,
    MEDICAL    = 1,
    ARCHERS    = 2,
    CAVE       = 3,
    TRENCH     = 4,
    MY_QUARTERS = 5,
    NUM_ROOMS  = 6,
};

// Directions are stored as column indices in the 2D array.
// NORTH=0, EAST=1, SOUTH=2, WEST=3
enum Direction {
    NORTH         = 0,
    EAST          = 1,
    SOUTH         = 2,
    WEST          = 3,
    NORTHEAST     = 4,
    NORTHWEST     = 5,
    NUM_DIRECTIONS = 6
};

// This sentinel value means "no room in this direction."
// -1 works because room indices are 0 or greater.
const int NO_CONNECTION = -1;

// -------------------------------------------------------
// FUNCTION PROTOTYPES (declared before main)
// -------------------------------------------------------
void printRoom(string roomNames[], string roomDescriptions[], int room);
void printExits(int connections[][NUM_DIRECTIONS], int room);
int  commandToDirection(const string& command);
void handleInteraction(int room);   // <-- NEW: storyline actions

// -------------------------------------------------------
// MAIN
// -------------------------------------------------------
int main()
{
    // ===================================================
    // PARALLEL ARRAYS
    // Both arrays are indexed by the same Room enum.
    // roomNames[ENCAMPMENT] and roomDescriptions[ENCAMPMENT]
    // describe the same place — that's what "parallel" means.
    // ===================================================
    string roomNames[NUM_ROOMS] = {
        "Main Encampment",   // index 0 = ENCAMPMENT
        "Medical Center",    // index 1 = MEDICAL
        "Archer's Point",    // index 2 = ARCHERS
        "Mysterious Cave",   // index 3 = CAVE
        "Trench"             // index 4 = TRENCH
        "My Quarters"        // index 5 = MY QUARTERS
    };

    string roomDescriptions[NUM_ROOMS] = {
        "The strongest point of the army. A vast encampment buzzing with soldiers.",
        "Where wounded are treated. The stench of blood fills the air.",
        "Operated by the archers. Arrows whistle past overhead.",
        "A strange cave near base. Something moves in the shadows.",
        "The meeting point of both armies. Screams echo from every direction."
        "My personal quarters. Stinks of sweat and rust"
    };

    // ===================================================
    // THE ADJACENCY LIST (2D array)
    //
    // Think of this as a table:
    //
    //              NORTH   EAST    SOUTH   WEST
    // ENCAMPMENT [  1,      2,      4,      3   ]
    // MEDICAL    [  -1,    -1,      0,     -1   ]
    // ARCHERS    [  -1,    -1,     -1,      0   ]
    // CAVE       [  -1,     0,     -1,     -1   ]
    // TRENCH     [   0,    -1,     -1,     -1   ]
    //
    // Reading row ENCAMPMENT: go North → room 1 (Medical),
    //   go East → room 2 (Archers), go South → room 4 (Trench),
    //   go West → room 3 (Cave).
    //
    // Reading row MEDICAL: only South leads somewhere (room 0).
    //   All other directions = -1 (wall).
    // ===================================================
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Step 1: Fill everything with NO_CONNECTION first.
    // A clean slate — assume all walls, then punch holes.
    for (int room = 0; room < NUM_ROOMS; room++)
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++)
            connections[room][dir] = NO_CONNECTION;

    // Step 2: Define the actual connections.
    // Each line punches one "doorway" between two rooms.
    // Note: connections are TWO-WAY — if you can go North
    // from A to B, you should be able to go South from B to A.

    // Main Encampment (center hub) connects to all 4 neighbors
    connections[ENCAMPMENT][NORTH] = MEDICAL;
    connections[ENCAMPMENT][EAST]  = ARCHERS;
    connections[ENCAMPMENT][SOUTH] = TRENCH;
    connections[ENCAMPMENT][WEST]  = CAVE;
    connections[ENCAMPMENT][NORTHEAST]  = MY_QUARTERS;


    // Return paths (reverse directions from each neighbor)
    connections[MEDICAL][SOUTH]  = ENCAMPMENT;
    connections[ARCHERS][WEST]   = ENCAMPMENT;
    connections[TRENCH][NORTH]   = ENCAMPMENT;
    connections[CAVE][EAST]      = ENCAMPMENT;
     connections[MY_QUARTERS][NORTHWEST]      = ENCAMPMENT;


    // ===================================================
    // GAME LOOP
    // Starts the player in the Encampment.
    // Keeps running until the player types "quit".
    // ===================================================
    int currentRoom = ENCAMPMENT;
    string command;

    cout << "=== WAR ZONE: TEXT ADVENTURE ===" << endl;
    cout << "Commands: north/n, east/e, south/s, west/w, look, interact, quit\n" << endl;

    // Print the starting room immediately
    printRoom(roomNames, roomDescriptions, currentRoom);
    printExits(connections, currentRoom);

    while (true)
    {
        cout << "\n> ";
        cin >> command;

        if (command == "quit") break;

        if (command == "look")
        {
            // Re-describe the current room
            printRoom(roomNames, roomDescriptions, currentRoom);
            printExits(connections, currentRoom);
        }
        else if (command == "interact" || command == "i")
        {
            // Storyline-specific actions per room
            handleInteraction(currentRoom);
        }
        else
        {
            // Try to interpret as a movement direction
            int direction = commandToDirection(command);

            if (direction == -1)
            {
                cout << "Unknown command. Try: north, east, south, west, look, interact, quit." << endl;
            }
            else
            {
                // THE KEY LOOKUP:
                // connections[currentRoom][direction] is ONE array lookup.
                // It returns the destination room number, or -1 if a wall.
                int nextRoom = connections[currentRoom][direction];

                if (nextRoom == NO_CONNECTION)
                {
                    cout << "A wall of sandbags blocks your path." << endl;
                }
                else
                {
                    currentRoom = nextRoom;  // move the player
                    printRoom(roomNames, roomDescriptions, currentRoom);
                    printExits(connections, currentRoom);
                }
            }
        }
    }

    cout << "\nYou retreat from the battlefield. Thanks for playing." << endl;
    return 0;
}

// -------------------------------------------------------
// FUNCTION DEFINITIONS
// -------------------------------------------------------

// Prints the room name and description.
void printRoom(string roomNames[], string roomDescriptions[], int room)
{
    cout << "\n--- " << roomNames[room] << " ---" << endl;
    cout << roomDescriptions[room] << endl;
}

// Scans the connections row for the current room and prints
// only the directions that have an actual destination.
void printExits(int connections[][NUM_DIRECTIONS], int room)
{
    const string dirNames[NUM_DIRECTIONS] = { "north", "east", "south", "west", "northeast", "northwest" };
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
    cout << endl;
}

// Converts a typed word into a direction index (0-3) or -1.
// Keeping abbreviations here means the game loop stays clean.
int commandToDirection(const string& command)
{
    if (command == "north" || command == "n") return NORTH;
    if (command == "east"  || command == "e") return EAST;
    if (command == "south" || command == "s") return SOUTH;
    if (command == "west"  || command == "w") return WEST;
    if (command == "northeast"  || command == "ne") return NORTHEAST;
    if (command == "northwest"  || command == "nw") return NORTHWEST;
    return -1;
}

// Storyline interactions — each room has its own event.
// In a larger game, these could change game state variables
// (health, ammo, morale) that you track with more variables.
void handleInteraction(int room)
{
    switch (room)
    {
        case ENCAMPMENT:
            cout << "You speak with the General. He hands you a map and says:\n";
            cout << "\"Head to the Archer's Point — we need covering fire NOW.\"" << endl;
            break;

        case MEDICAL:
            cout << "A nurse bandages your wounds. You recover 10 HP." << endl;
            // In a real game: playerHealth += 10;
            break;

        case ARCHERS:
            cout << "You order the archers to fire. A volley of arrows darkens the sky.\n";
            cout << "Enemy morale drops." << endl;
            break;

        case CAVE:
            cout << "You search the cave and find an old journal.\n";
            cout << "It reads: \"They come from the south. Do not trust the trench.\"" << endl;
            break;

        case TRENCH:
            cout << "You crouch low as bullets whiz overhead.\n";
            cout << "A soldier grabs you: \"Sir! They're flanking from the east!\"" << endl;
            break;
            
        case MY_QUARTERS:
            cout << "There is a moldy sandwich on my bed.\n";
            cout << "It is oddly hot in here" << endl;
            break;

        default:
            cout << "Nothing to interact with here." << endl;
            break;
    }
}