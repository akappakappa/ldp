/**
 * @file 01_Vector.cpp
 * @author github.com/akappakappa
 * @brief vector
 * @date 2020-11-04
 * 
 * Implement the class vector already discussed in our lectures, representing vectors of doubles with fixed length. The class should include: \n
 * 1. An int storing the length of the vector; \n
 * 2. A constructor accepting an int that represents the length of the vector; \n
 * 3. The get and set functions to operate on the vector elements (they should not check the boundaries of the vector); \n
 * 4. The safe_get and safe_set functions to operate on the vector elements, with boundary check; \n
 * 5. A destructor.
 * 
 */

#include <iostream>
#include <stdexcept>
using namespace std;

class vector
{
    public:
        /**
         * @brief Construct a new vector object
         * 
         * @param l length
         */
        vector(int l);
        /**
         * @brief Destroy the vector object
         * 
         */
        ~vector();
        /**
         * @brief Length manager
         * 
         * @return int length
         */
        int length() const;
        /**
         * @brief Gets element at index
         * 
         * @param i index
         * @return double 
         */
        double get(int i) const;
        /**
         * @brief Sets element at index
         * 
         * @param i index
         * @param v value
         */
        void set(int i, double v);
        /**
         * @brief Gets element at index safely
         * 
         * @param i index
         * @return double 
         */
        double safe_get(int i) const;
        /**
         * @brief Sets element at index safely
         * 
         * @param i index
         * @param v value
         */
        void safe_set(int i, double v);
        
    private:
        int lng;
        double *d;
};

vector::vector(int l)
{ d = new double[l] {0}; }

vector::~vector()
{ delete[] d; }

int vector::length() const
{ return lng; }

double vector::get(int i) const
{ return d[i]; }

void vector::set(int i, double v)
{ d[i] = v; }

double vector::safe_get(int i) const
{
    if (i >= lng)
        throw out_of_range("** out of bound **");
    get(i);
    return 0;
}

void vector::safe_set(int i, double v)
{
    if (i >= lng)
        throw out_of_range("** out of bound **");
    set(i, v);
}

int main()
{
    vector v (10);
    for (int i = 0; i < 10; i++)
        cout << v.get(i) << " ";
    cout << endl;

    cout << v.get(10) << " is out of bounds" << endl; // out of bounds;
    v.set(10, 10);
    cout << v.get(10) << " oob now modified" << endl; // out of bounds;
    
    for (int i = 0; i < 10; i++)
        v.set(i, 6);
    for (int i = 0; i < 10; i++)
        cout << v.get(i) << " ";
    cout << endl;

    try
    { v.safe_get(10); }
    catch(const exception& e)
    { cerr << e.what() << endl; }
    
    try
    { v.safe_set(10, 1); }
    catch(const exception& e)
    { cerr << e.what() << endl; }
    
    return 0;
}