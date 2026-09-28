#include <iostream>
using namespace std;

class Point {
private:
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
};



int main()
{
    Point *p1 = new Point();
    p1->setPoint(2,3);
    //Point *p2 = new Point(6,7);
    //Point *p3 = new Point(*p2);
    delete p1;
    //delete p2;
    //delete p3;
}