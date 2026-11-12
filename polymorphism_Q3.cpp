#include<iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a Circle" << endl;
    }
};

int main() {
    Circle c;

    Shape *basePtr;

    basePtr = &c;

    basePtr->draw();

    return 0;
}