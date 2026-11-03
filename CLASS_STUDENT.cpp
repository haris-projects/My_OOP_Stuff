#include<iostream>
using namespace std;

class Rectangle{

   private:
    int length;
    int width;
    public:
    Rectangle(){
        length=1;
        width=1;
    }
    Rectangle(int a , int b){
        length=a;
        width=b;
    }
    int cal_cul();

};
int Rectangle::cal_cul(){
    return length*width;
}


int main(){
Rectangle r1; 
cout<<"The area is: "<<r1.cal_cul()<<endl;
Rectangle r2( 7 , 9 );
cout<<"The area is: "<<r2.cal_cul()<<endl;

    return 0 ;
}