#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Iterator
{
public:
    virtual double* next() = 0;
};

class Vector_iterator : public Iterator
{
private:
    vector<double> v;
    int i;
public:
    Vector_iterator(const vector<double> &in) : v{in}, i{0} {}
    double* next() override
    {
        if (i < v.size())
            return &v.at(i++);
        return 0;
    }
};

class List_iterator : public Iterator
{
private:
    list<double> l;
    list<double>::iterator i;
public:
    List_iterator(const list<double> &in) : l{in}, i{l.begin()} {}
    double* next() override
    {
        if (i != l.end())
            return &*i++;
        return 0;
    }
};

int main()
{
    // tester
    vector<double> a {2, 3, 4, 5};
    list<double> b {6, 7, 8, 9};
    Vector_iterator v(a);
    List_iterator l(b);

    // testing function
    for (int i = 0; i < a.size(); i++)
        cout << *v.next() << " ";
    cout << endl;
    for (int i = 0; i < b.size(); i++)
        cout << *l.next() << " ";
    cout << endl;
    return 0;
}