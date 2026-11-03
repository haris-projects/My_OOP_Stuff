#include<iostream>
#include<string>
using namespace std;

class Employee{
public:
    int ID;
protected:
    double salray;
    string name;
public:
    Employee(int i, double s, string n) : ID(i), salray(s), name(n) { }
};

class Manager : protected Employee{
private:
    int Yearofexperience;
public:
    Manager(int id, double sal, string name, int Experience)
        : Employee(id, sal, name), Yearofexperience(Experience) { }
    void display();
    void setter(int y);
    void getter();
};

void Manager::setter(int y){
    Yearofexperience = y;
}

void Manager::getter(){
    cout<<Yearofexperience<<endl;
}

void Manager::display(){
    cout<<"Id of Manager : "<<ID<<endl;
    cout<<"Salary of Manager : "<<salray<<" Rupees"<<endl;
    cout<<"Name of Manager : "<<name<<endl;
    cout<<"Year of Experience of Manager : "<<Yearofexperience<<endl;
}

class Director : protected Manager{
public:
    Director(int i, double sal, string name, int Experience)
        : Manager(i, sal, name, Experience) { }   // all 4 values go up
    void display();
};

void Director::display(){
    cout<<"Id of Director : "<<ID<<endl;
    cout<<"Salary of Director : "<<salray<<" $"<<endl;
    cout<<"Name of Director : "<<name<<endl;
    cout<<"Year of Experience of Director : ";
    getter();                                     // getter already prints endl
}

int main(){
    Manager m1(1001, 80000, "Mr. Abdullah", 9);
    Director d1(3014, 25000, "Mr. Haris Iqbal", 13);

    m1.display();
    cout<<endl;
    d1.display();

    return 0;
}