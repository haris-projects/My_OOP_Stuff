#include<iostream>
using namespace std;

class Shape{
public:
    virtual void area() = 0;
};

class Rectangle:public Shape{
private:
    double length, width;

public:
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }

    void area() override;
};

void Rectangle::area(){
    cout<<"Rectangle Length : "<<length<<endl;
    cout<<"Rectangle Width : "<<width<<endl;
    cout<<"Rectangle Area : "<<length*width<<endl;
}

class Circle:public Shape{
private:
    double Radius;

public:
    Circle(double Radius){
        this->Radius = Radius;
    }

    void area() override;
};

void Circle::area(){
    cout<<"Circle Radius : "<<Radius<<endl;
    cout<<"Area Of Circle : "<<3.14*Radius*Radius<<endl;
}

int main(){
    Shape *p1;

    double length, width, radius;

    cout<<"Enter Length Value : ";
    cin>>length;

    cout<<"Enter Width Value : ";
    cin>>width;

    cout<<"Enter Radius of Circle : ";
    cin>>radius;
    cout<<endl;
    Rectangle r1(length, width);
    p1 = &r1;
    p1->area();
    cout<<endl;
    Circle c1(radius);
    p1 = &c1;
    p1->area();
     cout<<endl;
    return 0;
}