#include <iostream>
#include <string>
using namespace std;

class VehicleNode {
protected:
    string vehicleVIN;
    double operationalHours;

public:
    VehicleNode(string vin, double hours) {
        vehicleVIN = vin;
        operationalHours = hours;
        cout << "VehicleNode constructor called" << endl;
    }
};

class ElectricVehicle : virtual public VehicleNode {
protected:
    double batteryLevelCapacity;

public:
    ElectricVehicle(string vin, double hours, double battery) : VehicleNode(vin, hours) {
        batteryLevelCapacity = battery;
        cout << "ElectricVehicle constructor called" << endl;
    }
};

class AutonomousVehicle : virtual public VehicleNode {
protected:
    string sensorSuiteVersion;

public:
    AutonomousVehicle(string vin, double hours, string sensor) : VehicleNode(vin, hours) {
        sensorSuiteVersion = sensor;
        cout << "AutonomousVehicle constructor called" << endl;
    }
};

class AutonomousElectricTruck : public ElectricVehicle, public AutonomousVehicle {
public:
    AutonomousElectricTruck(string vin, double hours, double battery, string sensor)
        : VehicleNode(vin, hours),
          ElectricVehicle(vin, hours, battery),
          AutonomousVehicle(vin, hours, sensor) {
        cout << "AutonomousElectricTruck constructor called" << endl;
    }

    void generateFleetReport() {
        cout << "----- Fleet Report -----" << endl;
        cout << "VIN: " << vehicleVIN << endl;
        cout << "Operational Hours: " << operationalHours << endl;
        cout << "Battery Capacity: " << batteryLevelCapacity << " kWh" << endl;
        cout << "Sensor Suite Version: " << sensorSuiteVersion << endl;
    }
};

int main() {
    cout << "===== Creating truck =====" << endl;
    AutonomousElectricTruck truck("VIN-98765-XYZ", 1250.5, 100.0, "SensorSuite v4.2");

    cout << "\n===== Fleet Report =====" << endl;
    truck.generateFleetReport();

    cout << "\n===== Memory layout (sizeof) =====" << endl;
    cout << "sizeof(VehicleNode)           = " << sizeof(VehicleNode) << " bytes" << endl;
    cout << "sizeof(ElectricVehicle)       = " << sizeof(ElectricVehicle) << " bytes" << endl;
    cout << "sizeof(AutonomousVehicle)     = " << sizeof(AutonomousVehicle) << " bytes" << endl;
    cout << "sizeof(AutonomousElectricTruck) = " << sizeof(AutonomousElectricTruck) << " bytes" << endl;
    cout << "Two VehicleNode copies would need at least " << 2 * sizeof(VehicleNode) << " bytes just for VehicleNode" << endl;

    cout << "\n===== Proof of only ONE VehicleNode =====" << endl;
    ElectricVehicle* e = &truck;
    AutonomousVehicle* a = &truck;
    VehicleNode* n1 = e;
    VehicleNode* n2 = a;
    cout << "VehicleNode address via ElectricVehicle   : " << n1 << endl;
    cout << "VehicleNode address via AutonomousVehicle : " << n2 << endl;
    if (n1 == n2) {
        cout << "Same address -> only ONE VehicleNode subobject exists" << endl;
    }
    else {
        cout << "Different addresses -> two VehicleNode copies" << endl;
    }

    return 0;
}