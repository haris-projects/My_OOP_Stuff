#include <iostream>
#include <string>
using namespace std;

class Inventory {
private:
    string* items;
    int capacity;

public:
    // Parameterized constructor
    Inventory(int s) {
        if (s <= 0) {
            cout << "Warning!" << endl;
            capacity = 5;
        }
        else {
            capacity = s;
        }

        items = new string[capacity];
    }

    // Add an item
    void addItem(int index, string itemName) {

        if (index < 0 || index >= capacity) {
            cout << "Error: Invalid index" << endl;
            return;
        }

        if (items[index] != "") {
            cout << "Error: Slot already occupied" << endl;
            return;
        }

        items[index] = itemName;
    }

    // Remove an item
    void removeItem(int index) {

        if (index < 0 || index >= capacity) {
            cout << "Error: Invalid index" << endl;
            return;
        }

        if (items[index] == "") {
            cout << "Nothing to remove" << endl;
            return;
        }

        items[index] = "";
    }

    // Display inventory
    void showInventory() {
        bool empty = true;

        for (int i = 0; i < capacity; i++) {

            if (items[i] != "") {
                cout << "Slot " << i << ": " << items[i] << endl;
                empty = false;
            }
        }

        if (empty) {
            cout << "Inventory is empty" << endl;
        }
    }

    // Destructor
    ~Inventory() {
        delete[] items;
    }
};

int main() {

    Inventory inv(3);

    inv.addItem(0, "Sword");
    inv.addItem(2, "Shield");
    inv.addItem(3, "Potion");
    inv.addItem(0, "Axe");

    inv.removeItem(1);

    inv.showInventory();

    return 0;
}