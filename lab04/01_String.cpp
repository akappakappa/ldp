/**
 * @file 01_String.cpp
 * @author github.com/akappakappa
 * @brief bool is_palindrome(const std::string& s)
 * @date 2020-11-11
 * 
 * bool is_palindrome(const std::string& s); presentata a lezione. \n
 * Tale funzione ritorna true se la std::string s è palindroma, false altrimenti. \n
 *  \n
 * Leggete il codice sulle slide per il tempo che ritenete opportuno – ma senza prendere appunti di nessun tipo, \n
 * potete contare solo sulla vostra memoria. Quando pensate che sia sufficiente, \n
 * chiudete le slide (non potete più riaprirle da questo momento) e implementate in tre file distinti le tre funzioni, \n
 * ciascuna con un main che crea varie combinazioni di input opportuni e le passa alla funzione corrispondente \n
 * (devono quindi essere prodotti tre eseguibili diversi). \n
 * In questa implementazione non considerate la funzione read_word nelle slide, \n
 * ma limitatevi a creare le stringhe direttamente nel main – potete usare variabili locali automatiche o allocate dinamicamente.
 */

#include <iostream>
using namespace std;

bool is_palindrome(const string& s)
{
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1])
            return false;
    return true;
}

int main()
{
    string a = "gatto";
    if (is_palindrome(a))
        cout << "\"" << a << "\" is palindrome!" << endl;
    else
        cout << "\"" << a << "\" is NOT palindrome!" << endl;

    string b = "kayak";
    if (is_palindrome(b))
        cout << "\"" << b << "\" is palindrome!" << endl;
    else
        cout << "\"" << b << "\" is NOT palindrome!" << endl;

    string c = "z";
    if (is_palindrome(c))
        cout << "\"" << c << "\" is palindrome!" << endl;
    else
        cout << "\"" << c << "\" is NOT palindrome!" << endl;

    return 0;
}