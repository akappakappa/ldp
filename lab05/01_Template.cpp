/**
 * @file 01_Template.cpp
 * @author github.com/akappakappa
 * @brief Template class
 * @date 2020-12-16
 * 
 * Write a template function f() that adds the elements of one vector<T> to the elements of another; \n
 * for example, f(v1, v2) should do v1[i] += v2[i] for each element of v1.
 */

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void F(vector<T> &v1, vector<T> &v2)
{
    for (int i = 0; i < v1.size() && i < v2.size(); i++)
        v1.at(i) += v2.at(i);
}

int main()
{
    // tester
    vector<int> a(20, 1);
    vector<int> b(10, 2);

    cout << "> vector<int> a:" << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
    cout << "> vector<int> b:" << endl;
    for (int i = 0; i < b.size(); i++)
        cout << b.at(i) << " ";
    cout << endl;

    // testing function
    F(a, b);
    cout << "> vector<int> a:" << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;

    return 0;
}