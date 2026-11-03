#include <iostream>
using namespace std;

struct Grade
{
    float percentage;
    char grade;
};

struct Marks
{
    int subject[3];
    Grade g1;
};

struct Student
{
    int rollno;
    string name;
    Marks m1;
};

int main()
{
    int n, i, j;
    float total;

    cout << "Enter Total No of Students: ";
    cin >> n;

    Student* s1 = new Student[n];

    // Input students
    for(i = 0; i < n; i++)
    {
        cin.ignore();

        cout << "\nEnter Name of Student " << i + 1 << ": ";
        getline(cin, s1[i].name);

        cout << "Enter Roll no of Student " << i + 1 << ": ";
        cin >> s1[i].rollno;

        for(j = 0; j < 3; j++)
        {
            cout << "Enter Marks of Subject " << j + 1 << ": ";
            cin >> s1[i].m1.subject[j];
        }
    }

    cout << "\nEnter Total Marks of 3 Subjects: ";
    cin >> total;

    // Calculate percentage and grade
    for(i = 0; i < n; i++)
    {
        float sum = 0;

        for(j = 0; j < 3; j++)
        {
            sum += s1[i].m1.subject[j];
        }

        s1[i].m1.g1.percentage = (sum / total) * 100;

        // Grade
        if(s1[i].m1.g1.percentage > 80 &&
           s1[i].m1.g1.percentage <= 100)
        {
            s1[i].m1.g1.grade = 'A';
        }
        else if(s1[i].m1.g1.percentage > 70)
        {
            s1[i].m1.g1.grade = 'B';
        }
        else if(s1[i].m1.g1.percentage > 60)
        {
            s1[i].m1.g1.grade = 'C';
        }
        else
        {
            s1[i].m1.g1.grade = 'F';
        }
    }

    // Display result
    cout << "\n\n===== STUDENT RESULTS =====\n";

    for(i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Name: " << s1[i].name << endl;
        cout << "Roll No: " << s1[i].rollno << endl;

        cout << "Marks: ";

        for(j = 0; j < 3; j++)
        {
            cout << s1[i].m1.subject[j] << " ";
        }

        cout << endl;

        cout << "Percentage: "
             << s1[i].m1.g1.percentage << "%" << endl;

        cout << "Grade: "
             << s1[i].m1.g1.grade << endl;
    }

    // Find topper
    int topper = 0;

    for(i = 1; i < n; i++)
    {
        if(s1[i].m1.g1.percentage >
           s1[topper].m1.g1.percentage)
        {
            topper = i;
        }
    }

    cout << "\n===== TOPPER =====\n";
    cout << "Name: " << s1[topper].name << endl;
    cout << "Roll No: " << s1[topper].rollno << endl;
    cout << "Percentage: "
         << s1[topper].m1.g1.percentage << "%" << endl;
    cout << "Grade: "
         << s1[topper].m1.g1.grade << endl;

    // Free dynamic memory
    delete[] s1;
    s1 = nullptr;

    return 0;
}