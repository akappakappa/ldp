/**
 * @file 06_NamePairs.cpp
 * @author github.com/akappakappa
 * @brief Name_pairs object that stores vector of names and ages
 * @date 2020-10-09
 * 
 * Design and implement a Name_pairs class holding (name, age) pairs where name is a string and age is a double. \n
 * Represent that as a vector<string> (called name) and a vector<double> (called age) member. \n
 * Provide an input operation read_names() that reads a series of names (you can choose how to stop the input series) \n.
 * Provide a read_ages() operation that prompts the user for an age for each name, \n
 * Provide a print() operation that prints out the (name[i], age[i]) pairs (one per line) in the order determined by the name vector.
 * 
 */

#include <iostream>
#include <vector>
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

    private:
        vector<string> name;
        vector<double> age;
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

int main()
{
    Name_pairs s;
    s.read_names();
    s.read_ages();
    s.print();

    return 1;
}