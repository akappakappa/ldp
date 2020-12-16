/**
 * @file 01_NamePairs.cpp
 * @author github.com/akappakappa
 * @brief Name_pairs object that stores vector of names and ages
 * @date 2020-10-14
 * 
 * Design and implement a Name_pairs class holding (name, age) pairs where name is a string and age is a double. \n
 * Represent that as a vector<string> (called name) and a vector<double> (called age) member. \n
 * Provide an input operation read_names() that reads a series of names (you can choose how to stop the input series) \n.
 * Provide a read_ages() operation that prompts the user for an age for each name, \n
 * Provide a print() operation that prints out the (name[i], age[i]) pairs (one per line) in the order determined by the name vector. \n
 *  \n
 * Consider the Name_pairs class you developed for the previous assignment. Complete it by adding: \n
 * 1. a sort() operation that sorts the name vector in alphabetical order and reorganizes the age vector to match. \n
 * 2. A global operator<<. \n
 * 3. The operators == and !=.
 * 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @class Name_pairs
 * @brief Object containing vector of names and vector of age
 * 
 */
class Name_pairs
{
    public:
        /**
         * @brief Construct a new Name_pairs object
         * 
         */
        Name_pairs();
        /**
         * @brief Reads from input a series of names (strings), until input string is "q"
         * 
         */
        void read_names();
        /**
         * @brief Reads from input n ages, where n is the number of names read in read_names()
         * 
         */
        void read_ages();
        /**
         * @brief Prints the pair (name[i], age[i]), where i cycles from 0 to n
         * 
         */
        void print();
        /**
         * @brief Sorts the name vector in alphabetical order and reorganizes the age vector to match
         * 
         */
        void sort();
        /**
        * @brief Checks if 2 Name_pairs objects are identical
        * 
        * @param other other to compare
        * @return true if identical
        * @return false otherwise
        */
        bool operator==(Name_pairs& other);
        /**
         * @brief Checks if 2 Name_pairs objects are different
         * 
         * @param other other to compare
         * @return true if different
         * @return false otherwise
         */
        bool operator!=(Name_pairs& other);
        int size();
        string getName(int i);
        double getAge(int i);

    private:
        vector<string> name;
        vector<double> age;
        /**
         * @brief Selection sort
         * 
         * @param s Name
         * @param d Age
         */
        void selectionSort(vector<string>& s, vector<double>& d);
};

Name_pairs::Name_pairs()
{}

void Name_pairs::read_names()
{
    string str;
    cout << "> Insert names: \n";
    while (cin >> str)
    {
        if (!str.compare("q"))
            break;
        name.resize(name.size() + 1);
        name[name.size() - 1] = str;
    }
}

void Name_pairs::read_ages()
{
    cout << "> Insert ages: \n";
    age.resize(name.size());
    for (int i = 0; i < name.size(); i++)
        cin >> age[i];
}

void Name_pairs::print()
{
    cout << "> Name_pairs: \n";
    for (int i = 0; i < name.size(); i++)
        cout << name[i] << ", " << age[i] << "\n";
}

void Name_pairs::sort()
{
    selectionSort(name, age);
}

void Name_pairs::selectionSort(vector<string>& s, vector<double>& d)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < s.size(); j++)
            if (s[j].compare(s[min]) < 0)
                min = j;
        string tempS = s[min];
        double tempD = d[min];
        s[min] = s[i];
        d[min] = d[i];
        s[i] = tempS;
        d[i] = tempD;
    }
}

int Name_pairs::size()
{ return name.size(); }

string Name_pairs::getName(int i)
{ return name[i]; }

double Name_pairs::getAge(int i)
{ return age[i]; }

bool Name_pairs::operator==(Name_pairs& other)
{
    if (age.size() != other.size())
        return false;
    bool cnd = true;
    for (int i = 0; i < age.size(); i++)
        if (name[i] != other.getName(i) || age[i] != other.getAge(i))
        {
            cnd = false;
            break;
        }
    return cnd;
}

bool Name_pairs::operator!=(Name_pairs& other)
{ return !(*this == other); }

/**
 * @brief Outputs pairs of name - age
 * 
 * @param os output stream
 * @param n Name_pair object
 * @return ostream& well formatted output
 */
ostream& operator<<(ostream& os, Name_pairs& n)
{
    string str = "";
    for (int i = 0; i < n.size(); i++)
        str = str + n.getName(i) + ", " + to_string(n.getAge(i)) + "\n";
    return os << str;
}

int main()
{
    Name_pairs s;
    s.read_names();
    s.read_ages();
    s.sort();
    s.print();

    Name_pairs t;
    t.read_names();
    t.read_ages();
    t.sort();
    cout << t;

    if (s == t)
        cout << "stonks!" << endl;
    else if (s != t)
        cout << "not stonks :(" << endl;

    return 1;
}