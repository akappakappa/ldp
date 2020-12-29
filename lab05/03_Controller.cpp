/**
 * @file 03_Controller.cpp
 * @author github.com/akappakappa
 * @brief Controller class
 * @date 2020-12-16
 * 
 * Define a class Controller with four virtual functions on(), off(), set_level(int) and show(). \n
 * Derive at least two classes from Controller. One should be a simple test class \n
 * where show() prints out whether the class is set to on or off and what is the current level. \n
 * The second derived class should somehow control the line color of a Shape; \n
 * the exact meaning of “level” is up to you.
 */

#include <iostream>
using namespace std;

class Controller
{
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void set_level(int l) = 0;
    virtual void show() = 0;
};

class Controller_test : public Controller
{
private:
    bool status;
    int level;
public:
    Controller_test() : status{true}, level{0} {}
    void on() override { status = true; }
    void off() override { status = false; }
    void set_level(int l) override
    {
        if (!status)
            return;
        level = l;
    }
    void show() override { cout << "> status: " << status << " level: " << level << endl; }
};

class Shape_color_controller : public Controller
{
private:
	bool status;
    enum Color { white, red, green, blue, black };
    Color level;
public:
    Shape_color_controller() : status{true}, level{(Color)0} {}
    void on() override { status = true; }
	void off() override { status = false; }
	void set_level(int l)
    {
        if (!status)
            return;
        if (l >= 0 || l <= 4)
            level = (Color)l;
        else
            cout << "level not associated with color" << endl;
    }
	void show() override
    {
        string c;
        switch (level)
        {
            case 0: c = "white"; break;
            case 1: c = "red"; break;
            case 2: c = "green"; break;
            case 3: c = "blue"; break;
            case 4: c = "black"; break;
        }
        cout << "> status: " << status << " level: " << level << " color: " << c << endl;
    }
};

int main()
{
    Controller_test c1;
    c1.off();
    c1.set_level(2);
    c1.show();
    c1.on();
    c1.set_level(2);
    c1.show();

    Shape_color_controller c2;
    c2.off();
    c2.set_level(2);
    c2.show();
    c2.on();
    c2.set_level(1);
    c2.show();
    c2.set_level(2);
    c2.show();
    c2.set_level(3);
    c2.show();
    c2.set_level(4);
    c2.show();

    return 0;
}