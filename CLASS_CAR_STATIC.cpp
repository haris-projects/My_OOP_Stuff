#include<iostream>
using namespace std;

  class Car{
    public:
    int fuel ;
    int model;
    Car(int f , int m):fuel(f),model(m){
        count++;
    }
    static int count;
    void func();
  };
  void Car::func(){
    cout<<"the fuel in the car is : "<<fuel<<" Liter "<<endl;
    cout<<"the Model of  the car is : "<<model<<endl;
    count++;
    cout<<endl;
  }
  
  int Car::count=3;

int main(){
cout<<"Static Count Value "<<Car::count<<endl;   
Car c1(2,2005);
Car c2(4,2008);
Car c3(7,2015);
cout<<"Static Count Value "<<c1.count<<endl;
c1.func(); 
cout<<"Static Count Value "<<c1.count<<endl;
c2.func();
cout<<"Static Count Value "<<c1.count<<endl;
c3.func();
cout<<"Static Count Value "<<c1.count<<endl;


    return 0 ;
}