#include <iostream>
using namespace std;

struct Bill {
    float roomcharges;
    float medicineCharges;
    float total;
    float dis_total;
};

struct Patient {
    string name;
    int age;
    Bill b1;
};

void showHighBills(Patient* p1, int size) {

    float dis_count_total = 0;
    int count = 0;

    // Calculate bills
    for (int i = 0; i < size; i++) {

        p1[i].b1.total = p1[i].b1.roomcharges + p1[i].b1.medicineCharges;

        if (p1[i].b1.total > 20000) {
            p1[i].b1.dis_total = p1[i].b1.total * 0.05;
                count++;
            dis_count_total += p1[i].b1.dis_total;
        }
        else {
            p1[i].b1.dis_total = 0;
        }
    }

    if (count == 0) {
        cout << "No Patients qualify for Discount" << endl;
    }

    cout << "\n" << size << " Patients\n";

    for (int i = 0; i < size; i++) {
        if (p1[i].b1.total > 20000) {

            cout << "Name: " << p1[i].name
                 << ", Age: " << p1[i].age
                 << ", Original Bill: " << p1[i].b1.total
                 << ", Discount: " << p1[i].b1.dis_total
                 << endl;
        }
        else {
            cout << "Patient " << i + 1 << " is not eligible for Discount"  << endl;
        }
    }

    cout << "Discounted Patients: " << count << endl;
    cout << "Sum of Discounts: " << dis_count_total << endl;
}

int main() {

    int size;

    cout << "Enter size: ";
    cin >> size;

    Patient* p1 = new Patient[size];

    cin.ignore();

    for (int i = 0; i < size; i++) {

        cout << "Enter Patient " << i + 1 << " Name: ";
        getline(cin, p1[i].name);

        cout << "Enter Patient age: ";
        cin >> p1[i].age;

        cout << "Enter Room Charges for Patient "
             << i + 1 << ": ";
        cin >> p1[i].b1.roomcharges;

        cout << "Enter Medicine Charges for Patient "
             << i + 1 << ": ";
        cin >> p1[i].b1.medicineCharges;

        cin.ignore();
    }

    showHighBills(p1, size);

    delete[] p1;
    p1=nullptr;

    return 0;
}
