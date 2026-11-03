#include<iostream>
using namespace std;

class Employee{
    private:
    int id;
    protected:
    double baseSalary;
    public:
    void getterID(int id){
    this->id=id;
    cout<<"ID : "<<id<<endl;
    }
};
class Manager:public Employee{
private:
float bonus=0.20;
public:
Manager(double baseSalary){
    this->baseSalary=baseSalary;
}
void show1(){
cout<<"Basic Salary of Manager: "<<baseSalary+baseSalary*bonus<<endl;
}
};

class Developer:public Employee{
private:
float bonus=0.10;
public:
Developer(double baseSalary){
    this->baseSalary=baseSalary;
}
void show(){
    cout<<"Basic Salary of Developer: "<<(baseSalary+baseSalary*bonus)+500<<endl;
}
};
int main(){
    double mangerSa,DeveloperS;
    cout<<"Enter Manager Salary : ";
    cin>>mangerSa;

    cout<<"Enter Developer Salary : ";
    cin>>DeveloperS;


    Manager m1(mangerSa);

    m1.getterID(3014);
    m1.show1();
    Developer d1(DeveloperS);
    d1.getterID(100);
    d1.show();


    return 0 ;
}