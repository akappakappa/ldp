/**
 * @file 04a_Vector_v2.cpp
 * @author github.com/akappakappa
 * @brief Vector v2
 * @date 2020-11-21
 * 
 * Considerate: \n
 * - la class vector sviluppata nell’esercizio #2 del laboratorio 3, modificata con l’overloading dell’operator[] (richiesto nell’esercizion #2); \n
 * - la class Rational sviluppata nell’esercizio #1 del laboratorio 2. \n
 * Rivedete tali classi alla luce della checklist discussa nella lezione del 18/11. \n
 * Ponete attenzione ai costruttori espliciti e giustificate la vostra scelta nei commenti nel codice.
 * 
 */

#include <iostream>
#include <stdexcept>
using namespace std;

class vector
{
    public:
        /**
         * @brief Construct a new vector object of size = 0
         * 
         */
        vector();
        /**
         * @brief Construct a new vector object
         * 
         * @param l length
         */
        vector(int l);
        /**
         * @brief Construct a new vector::vector object
         * 
         * @param v vector to move
         */
        vector(vector&& v);
        /**
         * @brief Construct a new vector::vector object
         * 
         * @param v vector to copy
         */
        vector(const vector& v);
        /**
         * @brief Destroy the vector object
         * 
         */
        ~vector();
        /**
         * @brief Move assignment
         * 
         * @param v vector to move
         * @return vector& moved
         */
        vector& operator=(vector&& v);
        /**
         * @brief Copy assignment
         * 
         * @param v vector to copy
         * @return vector& copied
         */
        vector& operator=(const vector& v);
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

vector::vector()
{ d = new double[0]; }

vector::vector(int l)
{ d = new double[l] {0}; }

vector::vector(vector&& v)
    : lng{v.lng}, d{v.d}
{
    v.lng = 0;
    v.d = nullptr;
}

vector::vector(const vector& v)
    : lng{v.lng}, d{new double[lng]}
{ copy(v.d, v.d + lng, d); }

vector::~vector()
{ delete[] d; }

vector& vector::operator=(vector&& v)
{
    delete[] d;
    d = v.d;
    lng = v.lng;
    v.d = nullptr;
    v.lng = 0;
    return *this;
}

vector& vector::operator=(const vector& v)
{
    double *new_d = new double[v.lng];
    copy(v.d, v.d + lng, new_d);
    delete[] d;
    d = new_d;
    lng = v.lng;
    return *this;
}

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