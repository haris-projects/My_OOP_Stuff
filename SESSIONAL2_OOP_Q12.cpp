#include<iostream>
using namespace std;

class User{
    protected:
    string username;
    private:
    string pasword;
    public:
    User(string name , string password):username(name){
        this->pasword=password;
    }
    void accessPassword();
};
void User::accessPassword(){
    cout<<"Password Encrypted: "<<"*********"<<endl;
    cout<<endl;
}

class Admin: protected User{
     public:
     Admin(string na , string pas):User(na , pas){   } 
       
     void display();
};

void Admin::display(){
    cout<<endl;
    cout<<"User name : "<<username<<endl;
    accessPassword();
}
int main(){

Admin a1("Haris Iqbal" , "haris66@123");

a1.display();


    return 0 ;
}