#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point { int x, y; };
double distance(const Point &a, const Point &b) { return sqrt(pow((double)a.x - (double)b.x, 2) + pow((double)a.y - (double)b.y, 2)); }
// Carnot theorem
double angle_between(const Point &a, const Point &b, const Point &c)
    { return acos(((pow(distance(a, b), 2)) + (pow(distance(b, c), 2)) - (pow(distance(c, a), 2))) / (2 * (pow(distance(a, b), 2)) * (pow(distance(b, c), 2)))); }

class Shape
{
protected:
    vector<Point> points;
    string shape_name;
public:
    virtual string what_shape() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;
};

class Parallelogram : public Shape
{
public:
    Parallelogram() {};
    Parallelogram(initializer_list<Point> lst) { if (lst.size() != 4) throw invalid_argument(""); points.assign(lst); shape_name = "Parallelogram"; }
    Parallelogram(const Parallelogram& p) { points = p.points; shape_name = "Parallelogram"; }

    string what_shape() { return shape_name; }
    virtual double perimeter() override { return 2 * (distance(points.at(0), points.at(1)) + distance(points.at(1), points.at(2))); }
    // Brahmagupta's formula
    virtual double area() override { return sqrt((perimeter() / 2 - distance(points.at(0), points.at(1))) *
                                (perimeter() / 2 - distance(points.at(1), points.at(2))) *
                                (perimeter() / 2 - distance(points.at(2), points.at(3))) *
                                (perimeter() / 2 - distance(points.at(3), points.at(0))) - 
                                distance(points.at(0), points.at(1)) * distance(points.at(1), points.at(2)) *
                                distance(points.at(2), points.at(3)) * distance(points.at(3), points.at(0)) *
                                pow(cos((angle_between(points.at(3), points.at(0), points.at(1)) +
                                         angle_between(points.at(1), points.at(2), points.at(3))) / 2), 2)); }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus() {};
    Rhombus(initializer_list<Point> lst) { if (lst.size() != 4) throw invalid_argument(""); points.assign(lst); shape_name = "Rhombus"; }
    Rhombus(const Rhombus& p) { points = p.points; shape_name = "Rhombus"; }

    virtual double perimeter() override { return 4 * distance(points.at(0), points.at(1)); }
    virtual double area() override { return (distance(points.at(0), points.at(2))) * (distance(points.at(1), points.at(3))) / 2; }
};

class Rectangle : public Rhombus
{
public:
    Rectangle() {};
    Rectangle(initializer_list<Point> lst) { if (lst.size() != 4) throw invalid_argument(""); points.assign(lst); shape_name = "Rectangle"; }
    Rectangle(const Rectangle& p) { points = p.points; shape_name = "Rectangle"; }

    virtual double perimeter() override { return 2 * (distance(points.at(0), points.at(1)) + distance(points.at(1), points.at(2))); }
    virtual double area() override { return distance(points.at(0), points.at(1)) * distance(points.at(1), points.at(2)); }
};

class Square : public Rectangle
{
public:
    Square() {};
    Square(initializer_list<Point> lst) { if (lst.size() != 4) throw invalid_argument(""); points.assign(lst); shape_name = "Square"; }
    Square(const Square& p) { points = p.points; shape_name = "Square"; }

    double perimeter() override { return 4 * distance(points.at(0), points.at(1)); }
    double area() override { return pow(distance(points.at(0), points.at(1)), 2); }
};

int main()
{
    initializer_list<Point> parl {{0, 0}, {10, 0}, {12, 6}, {2, 6}};
    Parallelogram par(parl);
    cout << par.perimeter() << " " << par.area() << endl;

    initializer_list<Point> rhol {{0, 0}, {3, 4}, {0, 8}, {-3, 4}};
    Rhombus rho(rhol);
    cout << rho.perimeter() << " " << rho.area() << endl;

    initializer_list<Point> recl {{0, 0}, {10, 0}, {10, 5}, {0, 5}};
    Rectangle rec(recl);
    cout << rec.perimeter() << " " << rec.area() << endl;

    initializer_list<Point> squl {{0, 0}, {7, 0}, {7, 7}, {0, 7}};
    Square squ(squl);
    cout << squ.perimeter() << " " << squ.area() << endl;

    return 0;
}