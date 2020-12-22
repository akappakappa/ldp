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