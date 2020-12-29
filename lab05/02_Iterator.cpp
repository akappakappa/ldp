/**
 * @file 02_Iterator.cpp
 * @author github.com/akappakappa
 * @brief Iterator class
 * @date 2020-12-16
 * 
 * Define a class Iterator with a pure virtual function next() that returns a double*. \n
 * Now derive Vector_iterator and List_iterator from Iterator so that next() for a vector iterator \n
 * yields a pointer to the next element of a vector<double> and List_iterator does the same for a list<double>. \n
 * You initialize a Vector_iterator with a vector<double> and the first call of next() yields a pointer to its first element, if any. \n
 * If there is no next element, return 0. \n
 * Test this by using a function void print(Iterator&) to print the elements of a vector<double> and a list<double>.
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Iterator
{
public:
    virtual double* next() = 0;
    virtual int get_size() = 0;
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
    int get_size() override
    { return v.size(); }
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
    int get_size() override
    { return l.size(); }
};

void print(Iterator &itr)
{
    for (int i = 0; i < itr.get_size(); i++)
        cout << *itr.next() << " ";
    cout << endl;
}

int main()
{
    // tester
    vector<double> a {2, 3, 4, 5};
    list<double> b {6, 7, 8, 9};
    Vector_iterator v(a);
    List_iterator l(b);

    // testing functions
    print(v);
    print(l);
    
    return 0;
}