/**
 * @file 03_Fibonacci.cpp
 * @author github.com/akappakappa
 * @brief fibonacci() function that fills vector with the sequence
 * @date 2020-10-09
 * 
 * Create a vector of Fibonacci numbers and print them using the function from exercise 2. \n
 * To create the vector, write a function, fibonacci(x, y, v, n), where \n
 * integers x and y are ints, \n
 * v is an empty vector<int>, \n
 * and n is the number of elements to put into v; \n
 * v[0] will be x and v[1] will be y. \n
 * A Fibonacci number is one that is part of a sequence where each element is the sum of two previous ones. \n
 * For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, .... \n
 * Your fibonacci() function should make such a sequence starting with its x and y arguments.
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

int main()
{
    int first = 1;
    int second = 2;
    int numberOfElements = 10;
    vector<int> fib;
    fibonacci(first, second, fib, numberOfElements);    // creates vector sequence

    string label = "fibvector: ";                       // label
    print(label, fib);

    return 0;
}