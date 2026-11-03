#include<iostream>
using namespace std;

struct point{
    int x ;
    int y ;
};

point fun(int num1 ,int num2 ){

 point p1 ;
 p1.x=num1;
 p1.y=num2;

 return p1 ;

}



int main(){

point p1=fun(10 , 20);

cout<<" X "<<p1.x << " Y "<<p1.y<<endl ;

    return 0;
}