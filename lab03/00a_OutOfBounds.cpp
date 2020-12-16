/**
 * @file 00a_OutOfBounds.cpp
 * @author github.com/akappakappa
 * @brief out of bound
 * @date 2020-11-04
 * 
 * Create a program that: \n
 * 1. Allocates an array of 10 ints in the free store; \n
 * 2. Writes out of bound; \n
 * 3. Please check that the memory access out of bound causes the program to terminate. \n
 * Does this always happen? Why?
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int *a = new int[10] {0};
    a[200000000] = 1;
    cout << a[200000000] << endl;   // if it doesn't print, then successful

    return 0;
}