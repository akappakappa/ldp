#include <iostream>
#include <vector>
using namespace std;

/*struct Point { int x, y; };
class Shape
{
public:
    void draw() const;
    virtual void move(int dx, int dy);
    Point point(int i) const; // accesso ai punti
    int number_of_points() const;
    Shape(const Shape&) = delete;
    Shape& operator=(const Shape&) = delete;
    virtual ~Shape() {}
protected:
    Shape() {}
    Shape(initializer_list<Point> lst);
    virtual void draw_lines() const; // disegno
    void add(Point p); // aggiunge un punto
    void set_point(int i, Point p); // points[i] = p;
private:
    vector<Point> points; // non usato da tutte le Shape
    Color lcolor; // dalla libreria grafica
    Line_style ls; // dalla libreria grafica
    Color fcolor; // dalla libreria grafica
};*/

class Controller
{
protected:
    bool status;
    int level;
public:
    Controller() : status{true}, level{0} {};
    virtual void on();
    virtual void off();
    virtual void set_level(int l);
    virtual void show();
};

class Controller_test : public Controller
{
public:
    Controller_test() : Controller() {}

    void on() override { status = true; }
    void off() override { status = false; }
    void set_level(int l) override { level = l; }
    void show() override { cout << "> status: " << status << " level: " << level << endl; }
};

class Shape_color_controller : public Controller
{
public:
    Shape_color_controller(/* args */);
};

int main()
{
    Controller c;
    return 0;
}