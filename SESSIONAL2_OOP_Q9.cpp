#include<iostream>
using namespace std;

class School{
protected:
string name;
int ID;
School(string n , int i):name(n),ID(i){  }
};
class Student:protected School{
    private:
    char grade;
    public:
    Student(string na , int id , char g):School(na , id) , grade(g){
        cout<<"Student Name : "<<name<<endl;
        cout<<"Student ID: "<<ID<<endl;
        cout<<"Student Grade : "<<grade<<endl;
    }
};
class Teacher:protected School{
    private:
    string subject;
    public:
    Teacher(string nam , int idd ,string s):School(nam , idd) , subject(s){
        cout<<"Teacher name : "<<name<<endl;
        cout<<"Teacher ID : "<<ID<<endl;
        cout<<"Teacher Subject: "<<subject<<endl;
    }
};

int main(){

    Student s1("Haris iqbal ",3014,'A');
    Teacher t1("Sir Anwer ",1100,"Understanding of holly Quran");


    return 0 ;
}