/**
 * @file 03_StringCompare.cpp
 * @author github.com/akappakappa
 * @brief String compare
 * @date 2020-11-19
 * 
 * Write a function, int strcmp(const char* s1, const char* s2), that compares C-style string. \n
 * Let it return a negative number if s1 is lexicographically before s2, zero if s1 equals s2, \n
 * and a positive number if s1 is lexicographically after s2. Do not use any standard library functions. \n
 * Do not use subscripting: use the dereference operator * instead.
 * 
 */

#include <iostream>
using namespace std;

int strcmp(const char* s1, const char* s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            break;
        s1++;
        s2++;
    }

    if (*s1 < *s2)
        return -1;
    if (*s1 > *s2)
        return 1;
    return 0;
}

int main()
{
    char a[] = "cat";
    char b[] = "dog";
    char c[] = "LOL";
    char d[] = "LOL";
    char e[] = "sin";
    char f[] = "Sin";
    char g[] = "bin";
    char h[] = "bit";

    cout << strcmp(a, b) << endl;   // -1
    cout << strcmp(b, a) << endl;   // 1
    cout << strcmp(c, d) << endl;   // 0
    cout << strcmp(e, f) << endl;   // 1
    cout << strcmp(g, h) << endl;   // -1

    return 0;
}