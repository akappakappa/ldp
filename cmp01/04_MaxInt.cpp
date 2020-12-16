/**
 * @file 04_MaxInt.cpp
 * @author github.com/akappakappa
 * @brief fibMax() function that finds an approximate max int value
 * @date 2020-10-09
 * 
 * An int can hold integers only up to a maximum number. \n
 * Find an approximation of that maximum number by using fibonacci().
 * 
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Cretes vector containing the Fibonacci sequence with given size
 * 
 * @param x First number of the sequence
 * @param y Second number of the sequence
 * @param v Empty input vector
 * @param n Size of the vector
 */
void fibonacci(int x, int y, vector<int>& v, int n)
{
    v.resize(n);
    v[0] = x;
    v[1] = y;
    for (int i = 2; i < n; i++)
        v[i] = v[i - 1] + v[i - 2]; // sums last 2 number into current one
}

/**
 * @brief Uses fibonacci() to find max int by calculating fibonacci vector of increasing size
 * 
 */
void fibMax()
{
    int firstHighNumber = 100000000;
    int secondHighNumber = 100000000;
    int numberOfElements = 1;
    vector<int> maxInt {1};
    int max;

    while (maxInt[maxInt.size() - 1] > 0)                                       // if < 0 : overflow
    {
        fibonacci(firstHighNumber, secondHighNumber, maxInt, numberOfElements); // calls fibonacci()
        max = maxInt[maxInt.size() - 2];                                        // saves correct max number
        numberOfElements++;                                                     // update counter
    }
    cout << "> INT_MAX c++:      " << INT_MAX << "\n";                          // actual max int for reference
    cout << "> Int max approxed: " << max;                                      // prints approximation of max int                                                          
}

int main()
{
    fibMax();

    return 0;
}