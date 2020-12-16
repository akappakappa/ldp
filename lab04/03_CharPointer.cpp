/**
 * @file 03_CharPointer.cpp
 * @author github.com/akappakappa
 * @brief bool is_palindrome(const char* first, const char* last)
 * @date 2020-11-11
 * 
 * bool is_palindrome(const char* first, const char* last); - gli argomenti rappresentano il puntatore al primo e all’ultimo carattere di una stringa \n
 * (riferito all’ultimo carattere valido, non al terminatore ‘\0’). \n
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

bool is_palindrome(const char *first, const char *last)
{
    for (int i = 0; i < (last - first) / 2; i++)
        if (first[i] != first[(last - first) - i - 1])
            return false;
    return true;
}

int main()
{
    const char a[] = "gatto";
    if (is_palindrome(&a[0], &a[sizeof(a) - 1]))
        cout << "\"" << a << "\" is palindrome!" << endl;
    else
        cout << "\"" << a << "\" is NOT palindrome!" << endl;

    const char b[] = "kayak";
    if (is_palindrome(&b[0], &b[sizeof(b) - 1]))
        cout << "\"" << b << "\" is palindrome!" << endl;
    else
        cout << "\"" << b << "\" is NOT palindrome!" << endl;

    const char c[] = "z";
    if (is_palindrome(&c[0], &c[sizeof(c) - 1]))
        cout << "\"" << c << "\" is palindrome!" << endl;
    else
        cout << "\"" << c << "\" is NOT palindrome!" << endl;

    return 0;
}