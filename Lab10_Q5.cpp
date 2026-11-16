#include <iostream>
#include <vector>
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
    string getName() const { return name; }
    virtual ~DrawableShape() {           
        cout << "DrawableShape destroyed (" << name << ")\n";
    }
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
        cout << "Rendering Circle   | radius = " << radius
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
    vector<DrawableShape*> pipeline;
    pipeline.push_back(new CircleShape(5));
    pipeline.push_back(new RectangleShape(4, 6));
    pipeline.push_back(new CircleShape(2.5));
    pipeline.push_back(new RectangleShape(10, 3));

    cout << "=== Rendering Pipeline ===\n";
    double totalArea = 0;
    for (DrawableShape* shape : pipeline) {
        shape->render();                
        totalArea += shape->area();     
    }
    cout << "\nTotal area of all shapes: " << totalArea << "\n\n";

    cout << "=== Cleanup ===\n";
    for (DrawableShape* shape : pipeline) {
        delete shape;                    
    }
    pipeline.clear();

    return 0;
}