#include<iostream>
using namespace std;

class A{
    public:
    int num;
    A(){
        cout<<" A Constructed "<<num<<endl;
    }
    A(int n){
        num=n;
        cout<<" I am num constructor A "<<endl;
    }
    ~A(){
        cout<<"A Destructed "<<num<<endl;
    }
};
class B:public A{
    public:
   B(int n){
        num=n;
        cout<<" I am num constructor B "<<num<<endl;
    }
B(){
    cout<<" B constructed "<<num<<endl;

}
~B(){
    cout<<"B Destroyed "<<num<<endl;
}
};


int main(){

B b1(5);
b1.num=10;
A a1;
B b2;

    return 0;
}