#include<iostream>
using namespace std;

class Base{
private :
string name ;
int marks;
public:
Base(string n , int marks){
    name=n;
    this->marks=marks;
}
void Show();
~Base(){
    // delete name;
    cout<<"Base Class Destroy"<<endl;
}
};
void Base::Show(){
    cout<<"Name : "<<name<<endl;
    cout<<"Marks : "<<marks<<endl;
}
class Child:public Base{
    private:
    int rollno;
    public:
    Child(string n , int m , int r):Base(n , m) , rollno(r){ }
    void Show();
} ;
void Child::Show(){
    cout<<endl;
    cout<<"Roll no "<<rollno<<endl;
    Base::Show();
}

int main(){

    string name ;
    int marks , rollno;
    cout<<"Enter Your Name : ";
    getline(cin , name);
     cout<<"Enter RollNo : ";
    cin>>rollno;
    cout<<"Enter Marks : ";
    cin>>marks;
   
   
    Child childObj(name , marks , rollno);
    childObj.Show();



    return 0 ;
}