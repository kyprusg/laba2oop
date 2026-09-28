#include <iostream>
using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    Point() {
        cout << "Point()" << '\n';
        this->x = 0;
        y = 0;
    }
    Point(int x, int y) {
        cout << "Point(x, y)" << '\n';
        this->x = x;
        this->y = y;
    }
    Point(const Point &p) {
        cout << "Point(Point& p)" << '\n';
        x = p.x;
        y = p.y;
    }
    ~Point(){
        cout << this->x << " " << y << '\n';
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
    Circle(int x, int y, double radius): Point(x,y ){
        cout << "Circle(int x, int y, double radius)" << '\n';
        // this->x = x;
        // this->y = y;
        this->radius = radius;
    }
    Circle(const Circle &p): Point(p){
        cout << "Circle(const Circle &p)" << '\n';
        //this->x = p.x;
        //this->y = p.y;
        this->radius = p.radius;
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
    Triangle(const Triangle &s){
        cout << "Triangle(const Triangle &s" << '\n';
        p1 = s.p1;
        p2 = new Point(*(s.p2));
        p3 = new Point(*(s.p3));
    }
    ~Triangle(){
        delete p1;
        delete p2;
        delete p3;
        cout << "~Triangle()" << '\n';
    }
};
class Rectangle{
protected:
    Point p1;
    Point p2;
    Point p3;
    Point p4;
public:
    Rectangle(){
        cout << "Rectangle()"<< 'n';
    }
    Rectangle(int a,int b,int c,int d,int e,int f,int g,int h): p1(a,b),p2(a,b),p3(a,b),p4(a,b){
        cout << "Rectangle(int a,int b,int c,int d,int e,int f,int g,int h)"<< 'n';
    }
    Rectangle(const Rectangle &s):p1(s.p1),p2(s.p2),p3(s.p3),p4(s.p4){
        cout << "Rectangle(const Rectangle &s)"<< 'n';
    }
    ~Rectangle(){
        
    }
};

int main()
{
    Triangle *p1 = new Triangle;
    // Triangle *p2 = new Triangle(1,2,3,4,5,6);
    Triangle *p3 = new Triangle(*p1);
    // Circle *p1 = new Circle(1,2,3);
    // Circle *p2 = new Circle(*p1);
    // Triangle *p1 = new Triangle(1,2,3,4,5,6);
    // Triangle *p2 = p1;
    //Rectangle p1(1,2,3,4,5,6,7,8);
    //Rectangle p2(p1);
    delete p1;
    // delete p2;
    delete p3;
    return 0;
}