/**
 * @file 02_Char.cpp
 * @author github.com/akappakappa
 * @brief bool is_palindrome(const char[] s, int length)
 * @date 2020-11-11
 * 
 * bool is_palindrome(const char[] s, int length); - gli argomenti rappresentano una C-style string e la sua lunghezza \n
 * (per convenzione la lunghezza si riferisce ai caratteri validi ed esclude il terminatore ‘\0’); \n
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

bool is_palindrome(const char s[], int length)
{
    for (int i = 0; i < length / 2; i++)
        if (s[i] != s[length - i - 1])
            return false;
    return true;
}

int main()
{
    const char a[] = "gatto";
    if (is_palindrome(a, 5))
        cout << "\"" << a << "\" is palindrome!" << endl;
    else
        cout << "\"" << a << "\" is NOT palindrome!" << endl;

    const char b[] = "kayak";
    if (is_palindrome(b, 5))
        cout << "\"" << b << "\" is palindrome!" << endl;
    else
        cout << "\"" << b << "\" is NOT palindrome!" << endl;

    const char c[] = "z";
    if (is_palindrome(c, 1))
        cout << "\"" << c << "\" is palindrome!" << endl;
    else
        cout << "\"" << c << "\" is NOT palindrome!" << endl;

    return 0;
}