/**
 * @file 01_StringCopy.cpp
 * @author github.com/akappakappa
 * @brief String copy
 * @date 2020-11-19
 * 
 * Write a function, char* strdup(const char *), that copies a C-style string into memory it allocates on the free store. \n
 * Do not use any standard library functions. Do not use subscripting (cioè l’operatore []): use the dereference operator * instead.
 * 
 */

#include <iostream>
using namespace std;

char* strdup(const char *s)
{
    // count chars
    int n = 0;
    while (*(s + n) != '\0')
        n++;
    n++;
    
    // new string in free store
    char *dest = new char[n];

    // copy
    for (int i = 0; i < n; i++)
        *(dest + i) = *(s + i);
    
    return dest;
}

int main()
{
    char x[] = "abcd";
    char *new_x = strdup(x);
    cout << new_x << endl;

    return 0;
}