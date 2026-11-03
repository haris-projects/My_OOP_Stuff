#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    double salary;
};

void applyRaise(Employee* staff, int size, double percent)
{
    for (int i = 0; i < size; i++)
    {
        staff[i].salary += staff[i].salary * (percent / 100.0);
    }
}

void displayEmployees(Employee* staff, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nEmployee " << i + 1 << endl;
        cout << "Name: " << staff[i].name << endl;
        cout << "Salary: " << staff[i].salary << endl;
    }
}

int main()
{
    int size;

    cout << "Enter number of employees: ";
    cin >> size;

    Employee* staff = new Employee[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter details for employee " << i + 1 << endl;
       cin.ignore();
        cout << "Enter name: ";
        getline(cin, staff[i].name);

        cout << "Enter salary: ";
        cin >> staff[i].salary;
    }

    cout << "\nEmployees before raise:";
    displayEmployees(staff, size);

    double percent;

    cout << "\n\nEnter percentage raise: ";
    cin >> percent;

    applyRaise(staff, size, percent);

    cout << "\nEmployees after raise:";
    displayEmployees(staff, size);

    delete[] staff;

    return 0;
}