#include <iostream>
#include <string>
using namespace std;
const double PI = 3.14159265;
class DrawableShape {
protected:
    string name;

public:
    DrawableShape(string n) : name(n) {}

    virtual double area() const = 0;   
    virtual void render() const = 0;     

    virtual ~DrawableShape() {}         
};

class CircleShape : public DrawableShape {
private:
    double radius;

public:
    CircleShape(double r) : DrawableShape("Circle"), radius(r) {}

    double area() const override {
        return PI * radius * radius;
    }

    void render() const override {
        cout << "Rendering Circle    | radius = " << radius
             << " | area = " << area() << "\n";
    }
};

class RectangleShape : public DrawableShape {
private:
    double width, height;

public:
    RectangleShape(double w, double h)
        : DrawableShape("Rectangle"), width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void render() const override {
        cout << "Rendering Rectangle | " << width << " x " << height
             << " | area = " << area() << "\n";
    }
};

int main() {
    DrawableShape* shapes[4];            

    shapes[0] = new CircleShape(5);
    shapes[1] = new RectangleShape(4, 6);
    shapes[2] = new CircleShape(2.5);
    shapes[3] = new RectangleShape(10, 3);

    double totalArea = 0;

    cout << "=== Rendering Pipeline ===\n";
    for (int i = 0; i < 4; i++) {
        shapes[i]->render();            
        totalArea += shapes[i]->area();  
    }

    cout << "\nTotal area: " << totalArea << "\n";

    for (int i = 0; i < 4; i++) {
        delete shapes[i];               
    }

    return 0;
}