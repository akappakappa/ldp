/**
 * @file 02_StringFind.cpp
 * @author github.com/akappakappa
 * @brief String find
 * @date 2020-11-19
 * 
 * Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s. \n
 * Do not use any standard library functions. Do not use subscripting: use the dereference operator * instead.
 * 
 */

#include <iostream>
using namespace std;

char* findx(const char* s, const char* x)
{
    // count x
    int nx = 0;
    while (*(x + nx) != '\0')
        nx++;

    // count s
    int ns = 0;
    while (*(s + ns) != '\0')
        ns++;

    bool check = false;
    for (int i = 0; i < ns - nx + 1; i++)
    {
        if (*(s + i) != *x)
            continue;
        for (int j = 1; j < nx; j++)
        {
            if (*(s + i + j) != *(x + j))
            {
                i += j - 1;
                break;
            }
            else if (j + 1 == nx)
                check = true;
        }
        if (check)
            return (char*)(s + i);
    }
    return nullptr;

}

int main()
{
    char a[] = "oofoooffindeoofindefinderoo";
    char b[] = "finder";
    char *x = findx(a, b);
    cout << *x << endl; // should be 'f'
    cout << x << endl;  // should be "finderoo"

    return 0;
}