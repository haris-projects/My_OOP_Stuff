#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
    int quantity;
    double price;
};

double totalCost(const Item items[], int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        total += items[i].quantity * items[i].price;
    }

    return total;
}

int main()
{
    Item items[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "\nEnter details for item " << i + 1 << endl;

        cout << "Enter item name: ";
        getline(cin, items[i].name);

        cout << "Enter quantity: ";
        cin >> items[i].quantity;

        cout << "Enter price: ";
        cin >> items[i].price;
        cin.ignore();
    }

    double total = totalCost(items, 3);

    cout << "\nTotal Cost = " << total << endl;

    return 0;
}