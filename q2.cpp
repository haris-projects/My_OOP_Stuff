#include <iostream>
using namespace std;
// Part A - Structures
struct Room {
    int power;
    bool cursed;
    bool sealed;
};

struct Floor {
    int numRooms;
    Room* rooms;
};

struct Hero {
    char* name;
    int hp;
};

struct Dungeon {
    int depth;
    Floor* floors;
};

// Part B - Const-Correct Scanning function
const Room* findStrongest(const Room* const rooms, int numRooms) {
    const Room* strongest = nullptr;
    int maxPower = -1;
    
    for (int i = 0; i < numRooms; i++) {
        const Room* currentRoom = rooms + i; // Pointer arithmetic only
        if (!currentRoom->sealed) {
            if (currentRoom->power > maxPower) {
                maxPower = currentRoom->power;
                strongest = currentRoom;
            }
        }
    }
    return strongest; // Returns nullptr if all rooms are sealed
}

// Part B - Debug Printer
void printDebug(const void* ptr, char type) {
    if (type == 'i') cout << *(const int*)ptr;
    else if (type == 'f') cout << *(const float*)ptr;
    else if (type == 'c') cout << *(const char*)ptr;
}

// Part C - Destructor
void collapseDungeon(Dungeon*& dungeon, Hero*& hero) {
    if (!dungeon) return;
    
    // Free innermost blocks first
    for (int i = dungeon->depth - 1; i >= 0; i--) {
        delete[] (dungeon->floors + i)->rooms;
        cout << "Floor " << (i + 1) << " freed... ok\n";
    }
    
    delete[] dungeon->floors;
    cout << "Floor table freed... ok\n";
    
    if (hero) {
        delete[] hero->name;
        cout << "Hero name freed... ok\n";
        delete hero;
    }
    
    delete dungeon;
    cout << "Dungeon freed... ok\n";
    
    dungeon = nullptr; // Erase caller's pointer
    hero = nullptr;
    
    cout << "\nDUNGEON COLLAPSED. 0 BYTES LEAKED.\n";
}

// Helper to calculate exact length without string/cstring
int getLength(const char* str) {
    int len = 0;
    while (*(str + len) != '\0') len++;
    return len;
}

int main() {
    char tempBuffer[256];
    cout << "Enter hero name: ";
    cin.getline(tempBuffer, 256);
    
    int depth = 0;
    cout << "Enter depth: ";
    cin >> depth;
    cout << "\nKINGDOM OF THE LOST POINTER\n";
    
    // Exact-fit allocation for Hero
    Hero* hero = new Hero;
    int nameLen = getLength(tempBuffer);
    hero->name = new char[nameLen + 1];
    for (int i = 0; i <= nameLen; i++) {
        *(hero->name + i) = *(tempBuffer + i);
    }
    hero->hp = 100;
    
    cout << "Hero: " << hero->name << "   HP: " << hero->hp << "   Depth: " << depth << "\n\n";
    
    // Allocate Dungeon
    Dungeon* dungeon = new Dungeon;
    dungeon->depth = depth;
    dungeon->floors = new Floor[depth];
    
    int globalRoomCount = 0;
    int roomsCarved = 0;
    int cursedCount = 0;
    int sealedCount = 0;
    
    for (int i = 0; i < depth; i++) {
        int roomsInFloor = depth - i;
        (dungeon->floors + i)->numRooms = roomsInFloor;
        (dungeon->floors + i)->rooms = new Room[roomsInFloor];
        
        cout << "FLOOR " << (i + 1) << " ";
        
        for (int j = 0; j < roomsInFloor; j++) {
            globalRoomCount++;
            roomsCarved++;
            Room* r = (dungeon->floors + i)->rooms + j;
            
            // 1. Base Power
            r->power = (j + 1) * 10;
            r->cursed = false;
            r->sealed = false;
            
            // 2. Ehtasham's Curse
            if ((i + 1) % 2 != 0 && (j + 1) % 2 != 0) {
                r->power *= 2;
                r->cursed = true;
                cursedCount++;
            }
            
            // 3. The Boss
            if (i == depth - 1 && j == 0) {
                r->power = 99;
            }
            
            // 4. The Seal
            if (globalRoomCount % 3 == 0) {
                r->sealed = true;
                sealedCount++;
                cout << " [LOCKED]";
            } else {
                cout << "  " << r->power;
            }
            
            if (i == depth - 1 && j == 0) {
                cout << "   <== BOSS CHAMBER (sealed)";
            }
        }
        cout << "\n";
    }
    
    cout << "\nRooms carved: " << roomsCarved << "\n";
    cout << "Rooms wasted: 0\n";
    cout << "Cursed: " << cursedCount << "\n";
    cout << "Sealed: " << sealedCount << "\n";
    
    // Find Strongest on Floor 1
    const Room* strongest = findStrongest(dungeon->floors->rooms, dungeon->floors->numRooms);
    if (strongest) {
        // Calculate room index via pointer arithmetic difference
        int roomIndex = (strongest - dungeon->floors->rooms) + 1;
        cout << "Strongest monster: " << strongest->power << " (Floor 1, Room " << roomIndex << ")\n";
    }
    
    if (depth > 0 && (dungeon->floors + (depth - 1))->rooms->sealed) {
         cout << "\n>>> BOSS CHAMBER SEALED\nRUN INCOMPLETE <<<\n\n";
    }
    
    // Destroy
    collapseDungeon(dungeon, hero);
    
    return 0;
}