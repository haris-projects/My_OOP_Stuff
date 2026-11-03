#include <iostream>
#include <string>
using namespace std;

struct Address
{
    string city;
    string street;
};

struct Employee
{
    string name;
    Address address;
};

Employee* findByCity(Employee arr[], int size, string city)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].address.city == city)
        {
            return &arr[i];
        }
    }

    return nullptr;
}

int main()
{
    int size;

    cout << "Enter number of employees: ";
    cin >> size;
    cin.ignore();

    Employee* staff = new Employee[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter details for employee " << i + 1 << endl;

        cout << "Enter name: ";
        getline(cin, staff[i].name);

        cout << "Enter city: ";
        getline(cin, staff[i].address.city);

        cout << "Enter street: ";
        getline(cin, staff[i].address.street);
    }

    string searchCity;

    cout << "\nEnter city to search: ";
    getline(cin, searchCity);

    Employee* found = findByCity(staff, size, searchCity);

    if (found != nullptr)
    {
        cout << "\nEmployee found!" << endl;
        cout << "Name: " << found->name << endl;
        cout << "City: " << found->address.city << endl;
        cout << "Street: " << found->address.street << endl;

        cout << "\nEnter new street name: ";
        getline(cin, found->address.street);

        cout << "\nAfter updating:" << endl;
        cout << "Name: " << found->name << endl;
        cout << "City: " << found->address.city << endl;
        cout << "Street: " << found->address.street << endl;
    }
    else
    {
        cout << "\nNo employee found in that city." << endl;
    }

    delete[] staff;

    return 0;
}