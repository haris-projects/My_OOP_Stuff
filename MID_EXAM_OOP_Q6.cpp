#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string *name;
    int *rollno;
    double *cgpa;

public:
    // Single constructor with default arguments
    Student(string name = "unknown", int rollno = 0, double cgpa = 0.0) {

        this->name = new string(name);
        this->rollno = new int(rollno);

        // Validate CGPA
        if (cgpa > 4 || cgpa < 0) {
            cgpa = 0.0;
        }

        this->cgpa = new double(cgpa);
    }

    void display() const;

    ~Student() {
        delete name;
        delete rollno;
        delete cgpa;
    }
};

void Student::display() const {
    cout << "Name : " << *name
         << " | Roll no : " << *rollno
         << " | CGPA : " << *cgpa << endl;
}

int main() {

    Student s1;

    cout << "Student 1 (Default Constructor):" << endl;
    s1.display();

    cout << endl;

    Student s2("Haris Iqbal", 253014, 2.45);
    Student s3("Abdul Munim", 253056, 3.25);

    cout << "Student 2:" << endl;
    s2.display();

    cout << "Student 3:" << endl;
    s3.display();

    return 0;
}