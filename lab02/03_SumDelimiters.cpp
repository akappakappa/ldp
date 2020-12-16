/**
 * @file 03_SumDelimiters.cpp
 * @author github.com/akappakappa
 * @brief File output any delimiter
 * @date 2020-10-21
 * 
 * Write a program that produces the sum of all the whitespace-separated integers in a text file. \n
 * For example, “bears: 17 elephants 9” should output 26.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
using namespace std;

int main()
{
    ifstream in("03_input.txt");
    vector<char> v (1);
    int count = 0;
    int exp = 0;
    int sum = 0;

    // storing each char of the input file in a vector<char>
    while (in.get(v[count]) && in.good())
        count++;

    // scanning vector<char> backwards
    for (int i = count - 1; i >= 0; i--)
    {
        if (v[i] >= 48 && v[i] <= 57)                       // checking if it's a number (ascii)
        {
            sum = sum + ((int)v[i] - 48) * pow(10, exp);    // if number add to sum with correct 10^exp
            exp++;
        }
        else                                                // any delimiter, skip & set exp = 0
            exp = 0;
    }

    cout << sum << endl;

    in.close();
    return 0;
}