/**
 * @file 01_FreeStore.cpp
 * @author github.com/akappakappa
 * @brief Pointers and memory allocation
 * @date 2020-10-29
 * 
 * 1. Allocate an array of ten ints on the free store using new. \n
 * 2. Print the values of the ten ints to cout. \n
 * 3. Deallocate the array (using delete[]). \n
 * 4. Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os. \n
 * 5. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1. \n
 * 6. Allocate an array of ten ints, and assign its address to a variable p2. \n
 * 7. Copy the values from the array pointed to by p1 into the array pointed to by p2. \n
 * 8. Repeat 5-7 using a vector rather than an array.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints to ostream& an array/vector of length 10 given a pointer to the first element
 * 
 * @param os ostream&
 * @param a pointer to the first element
 */
void print_array10(ostream& os, int* a)
{
    for (int i = 0; i < 10; i++)
        os << *(a+i) << " ";
    os << endl;
}

int main()
{
    // 1. Allocate an array of ten ints on the free store using new.
    int *a = new int[10] {0};

    // 2. Print the values of the ten ints to cout.
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    // 4. Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os.
    print_array10(cout, a);

    // 3. Deallocate the array (using delete[]).
    delete[] a;
    print_array10(cout, a);

    // 5. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
    int b[] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int *p1 = &b[0];
    print_array10(cout, p1);

    // 6. Allocate an array of ten ints, and assign its address to a variable p2.
    int c[10] {0};
    int *p2 = &c[0];
    print_array10(cout, p2);

    // 7. Copy the values from the array pointed to by p1 into the array pointed to by p2.
    for (int i = 0; i < 10; i++)
        p2[i] = p1[i];
    print_array10(cout, p2);

    // 8. Repeat 5-7 using a vector rather than an array.
    vector<int> d {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int *p3 = &d[0];
    print_array10(cout, p3);
    vector<int> e (10);
    int *p4 = &e[0];
    print_array10(cout, p4);
    for (int i = 0; i < 10; i++)
        p4[i] = p3[i];
    print_array10(cout, p4);
}