
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int rollNumber;
    float GPA;
};

struct StudentDirectory
{
    Student** students;
    int size;
    int capacity;

    // Constructor
    StudentDirectory()
    {
        size = 0;
        capacity = 2;

        students = new Student*[capacity];
    }

    // Add a new student
    Student* addStudent(string name, int rollNumber, float GPA)
    {
        // If directory is full, double the capacity
        if (size == capacity)
        {
            int newCapacity = capacity * 2;

            Student** newStudents = new Student*[newCapacity];

            // Copy pointers, NOT Student objects
            for (int i = 0; i < size; i++)
            {
                newStudents[i] = students[i];
            }

            // Delete only the old pointer array
            delete[] students;

            // Make students point to the new array
            students = newStudents;

            capacity = newCapacity;
        }

        // Dynamically create a new Student
        Student* newStudent = new Student;

        newStudent->name = name;
        newStudent->rollNumber = rollNumber;
        newStudent->GPA = GPA;

        // Store its pointer in the directory
        students[size] = newStudent;

        size++;

        // Return pointer to newly created Student
        return newStudent;
    }

    // Search student by roll number
    Student* searchByRollNumber(int rollNumber)
    {
        for (int i = 0; i < size; i++)
        {
            if (students[i]->rollNumber == rollNumber)
            {
                return students[i];
            }
        }

        return nullptr;
    }

    // Destructor
    ~StudentDirectory()
    {
        // Delete every dynamically allocated Student
        for (int i = 0; i < size; i++)
        {
            delete students[i];
        }

        // Delete the pointer array itself
        delete[] students;
    }
};

int main()
{
    StudentDirectory directory;

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        int rollNumber;
        float GPA;

        cout << "\nEnter student " << i + 1 << " name: ";
        cin >> name;

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter GPA: ";
        cin >> GPA;

        Student* addedStudent =
            directory.addStudent(name, rollNumber, GPA);

        cout << "Student added successfully.\n";
        cout << "Address of new student: "
             << addedStudent << endl;
    }

    // Search
    int searchRoll;

    cout << "\nEnter roll number to search: ";
    cin >> searchRoll;

    Student* found = directory.searchByRollNumber(searchRoll);

    if (found != nullptr)
    {
        cout << "\nStudent Found!\n";
        cout << "Name: " << found->name << endl;
        cout << "Roll Number: " << found->rollNumber << endl;
        cout << "GPA: " << found->GPA << endl;
    }
    else
    {
        cout << "\nStudent not found.\n";
    }

    return 0;
}
