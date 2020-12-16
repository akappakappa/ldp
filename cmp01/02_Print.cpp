/**
 * @file 02_Print.cpp
 * @author github.com/akappakappa
 * @brief print() function for vectors, with label
 * @date 2020-10-09
 * 
 * Write a function print() that prints a vector of ints to cout. \n
 * Give it two arguments: a string for "labeling" the output and a vector.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Prints given array, with initial label
 * 
 * @param s Label of vector
 * @param v Input vector
 */
void print(string& s, const vector<int>& v)
{
    cout << s;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";  // prints element of the string
}

int main()
{
    string label = "intvector: ";       // label
    vector<int> num {0, 1, 2, 3, 4, 5}; // vector
    print(label, num);

    return 0;
}