#include<iostream>
using namespace std;

class Parent{
private:
double num1 , num2 ;

public:
Parent(double n1 ,double n2):num1(n1) , num2(n2){ }
void display();
void display2();

Parent operator+(Parent &p3){
    Parent temp(0.0 , 0.0 );
    temp.num1=this->num1+p3.num1;
    temp.num2=this->num2+p3.num2;
    return temp;
}
};
void Parent::display(){
    cout<<"Num1 Values : "<<num1<<endl;
    cout<<"Num2 Values : "<<num2<<endl;
}
void Parent::display2(){
    cout<<"Sum of Num1+Num1 of P1+P2 : "<<num1<<endl;
    cout<<"Sum of Num2+Num2 of P1+P2 : "<<num2<<endl;

}

int main(){
    cout<<endl;
    Parent p1(500 , 670);
    Parent p2(300 , 400);
    cout<<"Show P1 Values"<<endl;
    p1.display();
    cout<<"Show P2 Values"<<endl;
    p2.display();
    cout<<"show P1+P2 Values"<<endl;
    Parent p3=p1+p2;
    p3.display2();
     cout<<endl;



    return 0 ;
}