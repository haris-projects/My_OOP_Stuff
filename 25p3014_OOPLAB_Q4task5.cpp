#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

double distanceBetween(Point p1, Point p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    return sqrt(dx * dx + dy * dy);
}

Point midpoint(Point p1, Point p2)
{
    Point mid;

    mid.x = (p1.x + p2.x) / 2.0;
    mid.y = (p1.y + p2.y) / 2.0;

    return mid;
}

int main()
{
    Point p1, p2;

    cout << "Enter x-coordinate of Point 1: ";
    cin >> p1.x;

    cout << "Enter y-coordinate of Point 1: ";
    cin >> p1.y;

    cout << "\nEnter x-coordinate of Point 2: ";
    cin >> p2.x;

    cout << "Enter y-coordinate of Point 2: ";
    cin >> p2.y;

    double distance = distanceBetween(p1, p2);

    Point mid = midpoint(p1, p2);

    cout << "\nDistance = " << distance << endl;

    cout << "Midpoint = (" << mid.x << ", " << mid.y << ")" << endl;

    return 0;
}