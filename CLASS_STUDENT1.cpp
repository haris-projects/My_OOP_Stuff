#include<iostream>
using namespace std;
class Student{
    private:
    int rollno ;
    int marks;
    public:
    Student(int ro , int ma) : rollno(ro) , marks(ma){
    }
    void display(){
        cout<<"My Rollno is "<<rollno<<endl;
        cout<<"My marks is : "<<marks<<endl;
    }
    
};

int main(){

    int roll;
    int marks;
    cout<<"Enter your Roll No : ";
    cin>>roll;
    cout<<"Enter your Marks : ";
    cin>>marks;
    Student s1(roll,marks);
    s1.display();
    cout<<endl;

    return 0 ;

}