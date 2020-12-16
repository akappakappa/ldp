/**
 * @file 02_VectorOverload.cpp
 * @author github.com/akappakappa
 * @brief vector overloaded
 * @date 2020-11-04
 * 
 * Implement the class vector already discussed in our lectures, representing vectors of doubles with fixed length. The class should include: \n
 * 1. An int storing the length of the vector; \n
 * 2. A constructor accepting an int that represents the length of the vector; \n
 * 3. The get and set functions to operate on the vector elements (they should not check the boundaries of the vector); \n
 * 4. The safe_get and safe_set functions to operate on the vector elements, with boundary check; \n
 * 5. A destructor. \n
 *  \n
 * Consider the class developed in ex. 1 and substitute the get and set functions with the overloaded operator[]. \n
 * What type should it return? Why? Discuss this point with your colleagues.
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
         * @brief overloads operator[]
         * 
         * @param i index
         * @return double& 
         */
        double& operator[](int i);
        
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

double& vector::operator[](int i)
{ return d[i]; }

int main()
{
    vector v (10);
    for (int i = 0; i < 10; i++)
        cout << v[i] << " ";
    cout << endl;

    cout << v[10] << " is out of bounds" << endl; // out of bounds;
    v[10] = 10;
    cout << v[10] << " oob now modified" << endl; // out of bounds;
    
    for (int i = 0; i < 10; i++)
        v[i] = 6;
    for (int i = 0; i < 10; i++)
        cout << v[i] << " ";
    cout << endl;
    
    return 0;
}