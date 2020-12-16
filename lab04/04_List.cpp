/**
 * @file 04_List.cpp
 * @author github.com/akappakappa
 * @brief list
 * @date 2020-11-11
 * 
 * Considerate la struttura Link vista a lezione, che implementa un nodo di una lista concatenata: \n
 * struct Link { \n
 *     std::string value; \n
 *     Link* prev; \n
 *     Link* succ; \n
 *     Link(const string& v, Link* p = nullptr, Link* s = nullptr) \n
 *         : value{v}, prev{p}, succ{s} {} \n
 * }; \n
 * Controllate gli appunti per un tempo a piacere, dopodiché chiudeteli ed espandete la struttura implementando: \n
 * 1. La funzione push_back che aggiunge un elemento in coda alla lista; \n
 * 2. La funzione pop_back che rimuove l’ultimo elemento della lista \n
 * (e lo ritorna, senza liberare memoria, al chiamante – il chiamante deve liberare la memoria). \n
 * Per ciascuna funzione scegliete una combinazione opportuna di argomenti da usare. \n
 * Il punto di partenza per la lista (head) è un puntatore al primo elemento, \n
 * puntatore che deve essere aggiornato in caso di push_front o pop_front usando il return value di queste funzioni.
 * 
 */

#include <iostream>
using namespace std;

struct Link
{
    string value;
    Link* prev;
    Link* next;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, next{s}
    {}
};

void push_front(Link *&l, string s)
{
    if (!l)
    {
        l = new Link{s, nullptr, nullptr};
        return;
    }
    Link* tmp = new Link{s, nullptr, l};
    l->prev = tmp;
    l = tmp;
}

string pop_front(Link *&l)
{
    string ret = l->value;
    if (l->next)
    {
        l = l->next;
        l->prev = nullptr;
    }
    else
        l = nullptr;
    return ret;
}

void push_back(Link *&l, string s)
{
    if (!l)
    {
        l = new Link{s, nullptr, nullptr};
        return;
    }
    Link* tmp = l;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new Link{s, tmp, nullptr};
}

string pop_back(Link *&l)
{
    Link* tmp = l;
    while (tmp->next)
        tmp = tmp->next;
    string ret = tmp->value;
    if (tmp->prev)
        tmp->prev->next = nullptr;
    else
        l = nullptr;
    return ret;
}

int main()
{
    Link* list = new Link{"a", nullptr, nullptr};
    
    cout << pop_back(list) << endl;
    push_front(list, "b");
    cout << pop_front(list) << endl;
    push_back(list, "c");
    cout << pop_back(list) << endl;

    return 0;
}