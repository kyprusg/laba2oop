#include <iostream>
using namespace std;

class Point {
public:
    int x;
    int y;
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
};


int main()
{
    Point p1;
    Point p2(6,7);
    Point p3(p2);
}