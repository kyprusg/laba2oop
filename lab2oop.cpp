#include <iostream>
using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    Point() {
        cout << "Point()" << '\n';
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        cout << "Point(int x, int y)" << '\n';
        this->x = x;
        this->y = y;
    }
    Point(const Point &p) {
        cout << "Point(Point* p)" << '\n';
        x = p.x;
        y = p.y;
    }
    ~Point(){
        cout << x << " " << y << '\n';
        cout << "~Point()" << '\n';
    }
    void setPoint(int x, int y){
        this->x = x;
        this->y = y;
    }
    void move(int dx, int dy);
};
void Point::move(int dx, int dy){
    x = x + dx;
    y = y + dy;
}

class Circle: public Point{
protected:
    double radius;
public:
    Circle(): Point(){
        cout << "Circle()" << '\n';
        radius = 0;
    }
    Circle(int x, int y, double radius): Point(x,y){
        cout << "Circle(int x, int y, double radius)" << '\n';
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    Circle(const Circle *p){
        cout << "Circle(const Circle *p)" << '\n';
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    ~Circle(){
        cout << x << " " << y << ' ' << "radius=" << radius <<'\n';
        cout << "~Circle()" << '\n';
    }
    void setRadius(double radius){
        this->radius = radius;
    }
};

class Triangle{
protected:
    Point *p1;
    Point *p2;
    Point *p3;
public:
    Triangle(){
        cout << "Triangle()" << '\n';
        p1 = new Point;
        p2 = new Point;
        p3 = new Point;
    }
    Triangle(int x1,int y1, int x2,int y2, int x3, int y3){
        cout << "Triangle(int x1,int y1, int x2,int y2, int x3, int y3)" << '\n';
        p1 = new Point(x1,y1);
        p2 = new Point(x2,y2);
        p3 = new Point(x3,y3);
    }
};

int main()
{
    Point *p1 = new Circle(1,2,5);
    Circle *p2 = new Circle(6,7,6);
    delete p1;
    delete p2;
    return 0;
}