#include<iostream>
using namespace std;

class Employee{
    private:
    string name;
    int marks;
    char grade;
    float gpa;

    public:
    void setter(string na, int ma, char gr , float gp);
    void getter();

};
void Employee::setter(string na, int ma, char gr , float gp){
    name=na;
    marks=ma;
    grade=gr;
    gpa=gp;
}
void Employee::getter(){
    cout<<"The name of the Studdent is : "<<name<<endl;
    cout<<"The marks of the Studdent is : "<<marks<<endl;
    cout<<"The grade of the Studdent is : "<<grade<<endl;
    cout<<"The GPA of the Studdent is : "<<gpa<<endl;
    
}

int main(){
    Employee emp1;
    string name;
    int marks;
    char grade ;
    float gpa;
    cout<<"Enter your name : "<<endl;
    getline(cin,name);
    cout<<"Enter your marks : "<<endl;
    cin>>marks ;
    cout<<"Enter your grade : "<<endl;
    cin>>grade;
    cout<<"Enter your GPA: "<<endl;
    cin>>gpa;
   
    cout<<endl;
     cout<<"Print All elements Through sample OBJ"<<endl;
    emp1.setter( name , marks ,grade , gpa);
    emp1.getter();
    
    cout<<endl;
     cout<<"Print All elements Through POINTER"<<endl;
    
    Employee *emp2=new Employee;
    emp2=&emp1;
    emp2->setter(name , marks ,grade , gpa);
    emp2->getter();
 
     cout<<endl;
     cout<<"Print All elements Through SAMPLE ALIASING/ REFFRENCE"<<endl;

     Employee &emp3=emp1;
     emp3.setter(name , marks ,grade , gpa);
     emp3.getter();


    return 0 ;
}