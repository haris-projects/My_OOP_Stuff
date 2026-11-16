#include <iostream>
using namespace std;

class SmartDevice {
protected:
    int energy;

public:
    SmartDevice(int units) : energy(units) {}
    virtual void Energy_compution(double) = 0;
    virtual ~SmartDevice() {} // Added virtual destructor
};

class SmartThermostat : public SmartDevice {
public:
    // Explicitly call the SmartDevice constructor
    SmartThermostat(int unit) : SmartDevice(unit) {}
    void Energy_compution(double price) override;
};

void SmartThermostat::Energy_compution(double price) {
    cout << "Total Units Consumed By Smart Thermostat: " << energy << endl;
    cout << "Price per Unit  : " << price << endl;
    cout << "Total Bill : " << energy * price << endl;
}

class SmartLight : public SmartDevice {
public:
    // Explicitly call the SmartDevice constructor
    SmartLight(int u) : SmartDevice(u) {}
    void Energy_compution(double price) override;
};

void SmartLight::Energy_compution(double price) {
    cout << "Total Units Consumed by Light: " << energy << endl;
    cout << "Price per Unit  : " << price << endl;
    cout << "Total Bill OF Light: " << energy * price << endl;
}

int main() {
    SmartDevice* Device[2];
    Device[0] = new SmartThermostat(10);
    Device[1] = new SmartLight(15);

    double price;
    cout << "Enter Price of One Unit: ";
    cin >> price;

    for (int i = 0; i < 2; i++) {
        Device[i]->Energy_compution(price);
    }

    for (int i = 0; i < 2; i++) {
        delete Device[i];
    }

    return 0;
}
