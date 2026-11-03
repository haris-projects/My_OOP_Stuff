#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double gpa;

public:
    //constructor using list initializer
   Student() : name(""), age(0), gpa(0.0) {
   
   cout<<"default con";
   }
     
   Student& setName(string n) {
       this->name = n;   
       return *this;     
   }

   Student& setAge(int a) {
       this->age = a;
       return *this;
   }

   Student& setGPA(double g) {
       this->gpa = g;
       return *this;
   }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    Student s1;
    s1.show();

   
    s1.setName("Ali").setAge(20).setGPA(3.7);
   s1.show();
   

    return 0;
}