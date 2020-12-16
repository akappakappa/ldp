/**
 * @file 00b_FreeStore.cpp
 * @author github.com/akappakappa
 * @brief free store
 * @date 2020-11-04
 * 
 * Create a program that: \n
 * 1. Defines a vector<int> my_vector and uses it to store 10 ints; \n
 * 2. Defines a vector<int>* my_pointer and allocates such vector in the free store; then stores 10 ints in such vector; \n
 * 3. Why is my_vector more efficient than the vector pointed to by my_pointer?
 * 
 */

#include <vector>
using namespace std;

int main()
{
    vector<int> my_vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // più efficiente perchè gestisce ottimalmente la memoria
    vector<int> *my_pointer = new vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    return 0;
}