#include<iostream>
using namespace std;

class Point{

    private:
    int x,y ;
    public:
    Point(int xx=4 ,int yy=8 ):x(xx),y(yy){
        // cout<<endl;
        // cout<<x<<" "<<y<<endl;
    }

    void show(){
        cout<<endl;
        cout<<x<<" "<<y<<endl;
    }
    };
int main(){
Point p1;
p1.show();
Point p2(p1);
p2.show();

    return 0 ;
}