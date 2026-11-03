#include <iostream>
#include <iomanip>
using namespace std;

class Item {
private:
    double cost;
    int units;
public:
    Item() : cost(0), units(0) {}
    Item(double c, int u) : cost(c), units(u) {}

    void setCost(double c) { cost = c; }
    void setUnits(int u)   { units = u; }

    double getCost() const { return cost; }
    int getUnits() const   { return units; }

    double totalValue() const { return cost * units; }
};

void showMostValuable(Item arr[], int n) {
    int maxIndex = 0;
    double maxVal = arr[0].totalValue();

    for (int i = 1; i < n; i++) {
        if (arr[i].totalValue() > maxVal) {   // strict > so first item wins a tie
            maxVal = arr[i].totalValue();
            maxIndex = i;
        }
    }
    cout << "Most valuable: Item " << maxIndex + 1
         << " (Total = " << maxVal << ")" << endl;
}

int main() {
    cout << fixed << setprecision(2);

    Item items[4];
    double grand = 0;

    for (int i = 0; i < 4; i++) {
        double c;
        int u;

        cout << "Item " << i + 1 << ": ";
        cin >> c >> u;

        while (c < 0 || u < 0) {
            cout << "Invalid, enter again: ";
            cin >> c >> u;
        }

        items[i].setCost(c);
        items[i].setUnits(u);
        grand += items[i].totalValue();
    }

    cout << "Grand total: " << grand << endl;
    showMostValuable(items, 4);

    return 0;
}