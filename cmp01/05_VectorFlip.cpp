/**
 * @file 05_VectorFlip.cpp
 * @author github.com/akappakappa
 * @brief flipNoChange() and flipChange() functions that reverse content of given vector
 * @date 2020-10-09
 * 
 * Write two functions that reverse the order of elements in a vector<int>. \n
 * For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. \n
 * The first reverse function should produce a new vector with the reversed sequence, leaving its original vector unchanged. \n
 * The other reverse function should reverse the elements of its vector without using any other vectors.
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
 * @brief Flips the order of the elements of a given vector, without changing it
 * 
 * @param v Input vector
 * @return New flipped vector
 */
vector<int> flipNoChange(const vector<int>& v)
{
    vector<int> dest(v.size());         // new destination vector
    for (int i = 0; i < v.size(); i++)
        dest[i] = v[v.size() - i - 1];  // copying elements from 0:size-1 to size-1:0
    return dest;
}

/**
 * @brief Flips the order of the elements of a given vector, changing it
 * 
 * @param v Input vector
 */
void flipChange(vector<int>& v)
{
    int tmp;                                // temporary element storage
    for (int i = 0; i < v.size() / 2; i++)  // scans vector from 0 to middle element, works with even and odd numbers
    {
        tmp = v[i];                         // tmp <- first half
        v[i] = v[v.size() - i - 1];         // first half <- last half
        v[v.size() - i - 1] = tmp;          // last half <- tmp
    }
}

int main()
{
    vector<int> num {0, 1, 2, 3, 4, 5, 6, 7};   // vector

    string a = "vector:                   ";    // label
    print(a, num);                              // check
    cout << "\n";

    vector<int> flipped1 = flipNoChange(num);   // flip no change
    string b = "flipped vector:           ";    // label
    print(b, flipped1);                         // print
    cout << "\n";
    string c = "unchanged vector:         ";    // label
    print(c, num);                              // check
    cout << "\n";

    flipChange(num);                            // flip change
    string d = "flipped & changed vector: ";    // label
    print(d, num);                              // print

    return 0;
}