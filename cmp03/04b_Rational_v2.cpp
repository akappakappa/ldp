/**
 * @file 04b_Rational_v2.cpp
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
using namespace std;

/**
 * @class Rational
 * @brief Object that stores number in num and den
 * 
 */
class Rational
{
    public:
        /**
         * @brief Construct a new Rational object = 0
         * 
         */
        Rational();
        /**
         * @brief Construct a new Rational object
         * 
         * @param n numerator
         * @param d denominator
         */
        Rational(int& n, int& d);
        /**
         * @brief Construct a new Rational object
         * 
         * @param n numerator (denominator = 1)
         */
        Rational(int& n);
        /**
         * @brief Construct a new Rational object
         * 
         * @param r rational to move
         */
        Rational(Rational&& r);
        /**
         * @brief Construct a new Rational object
         * 
         * @param r rational to copy
         */
        Rational(const Rational& r);
        /**
         * @brief Get the Num
         * 
         * @return int 
         */
        int getNum();
        /**
         * @brief Get the Den
         * 
         * @return int 
         */
        int getDen();
        /**
         * @brief Move assgnment
         * 
         * @param r rational to move
         * @return Rational& moved
         */
        Rational& operator=(Rational&& r);
        /**
         * @brief Copy assignment
         * 
         * @param r rational to copy
         * @return Rational& copied
         */
        Rational& operator=(const Rational& r);
        /**
         * @brief Overload =
         * 
         * @param r other Rational
         */
        void operator=(Rational& r);
        /**
         * @brief Overload =
         * 
         * @param i other int
         */
        void operator=(int i);
        /**
         * @brief Double value of the Rational number
         * 
         * @return double 
         */
        double toDouble();
        /**
         * @brief Simplifies Rationl number, Euclidean algorithm
         * 
         */
        void minTerm();

    private:
        int num;
        int den;
};

Rational::Rational()
    : num{0}, den{1}
{}

Rational::Rational(int& n, int& d)
{
    if (d < 0)
    {
        n = 0 - n;
        d = 0 - d;
    }
    num = n;
    den = d;
    minTerm();
}

Rational::Rational(int& n)
    : num{n}, den{1}
{}

Rational::Rational(Rational&& r)
    : num{r.num}, den{r.den}
{
    r.num = 0;
    r.den = 0;
}

Rational::Rational(const Rational& r)
    : num{r.num}, den{r.den}
{}

int Rational::getNum()
{ return num; }

int Rational::getDen()
{ return den; }

Rational& Rational::operator=(Rational&& r)
{
    num = r.num;
    den = r.den;
    r.num = 0;
    r.den = 0;
    return *this;
}

Rational& Rational::operator=(const Rational& r)
{
    num = r.num;
    den = r.den;
    return *this;
}

void Rational::operator=(Rational& r)
{
    num = r.getNum();
    den = r.getDen();
}

void Rational::operator=(int i)
{
    num = i;
    den = 1;
}

double Rational::toDouble()
{
    double ret = (double)num / (double)den;
    return ret;
}

void Rational::minTerm()
{
    bool sign = true;
    if (num < 0)
    {
        num = 0 - num;
        sign = false;
    }
    int tmpN = num;
    int tmpD = den;
    int gcd = num % den;

    // Euclidean algorithm
    while (gcd != 0)
    {
        tmpN = tmpD;
        tmpD = gcd;
        gcd = tmpN % tmpD;
    }
    gcd = tmpD;

    if (!sign)
        num = 0 - num;
    num /= gcd;
    den /= gcd;
}

/**
 * @brief Overloads +
 * 
 * @param r1 first rational
 * @param r2 second rational
 * @return Rational 
 */
Rational operator+(Rational& r1, Rational& r2)
{
    int a = r1.getNum() * r2.getDen() + r1.getDen() * r2.getNum();
    int b = r1.getDen() * r2.getDen();
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads +
 * 
 * @param r rational
 * @param i int
 * @return Rational 
 */
Rational operator+(Rational& r, int i)
{
    int a = r.getNum() + r.getDen() * i;
    int b = r.getDen();
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads +
 * 
 * @param i int
 * @param r rational
 * @return Rational 
 */
Rational operator+(int i, Rational& r)
{
    Rational ret = r + i;
    return ret;
}

/**
 * @brief Overloads -
 * 
 * @param r1 first rational
 * @param r2 second rational
 * @return Rational 
 */
Rational operator-(Rational& r1, Rational& r2)
{
    int a = r1.getNum() * r2.getDen() - r1.getDen() * r2.getNum();
    int b = r1.getDen() * r2.getDen();
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads -
 * 
 * @param r rational
 * @param i int
 * @return Rational 
 */
Rational operator-(Rational& r, int i)
{
    int a = r.getNum() - r.getDen() * i;
    int b = r.getDen();
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads -
 * 
 * @param i int
 * @param r rational
 * @return Rational 
 */
Rational operator-(int i, Rational& r)
{
    Rational ret = r - i;
    return ret;
}

/**
 * @brief Overloads *
 * 
 * @param r1 first rational
 * @param r2 second rational
 * @return Rational 
 */
Rational operator*(Rational& r1, Rational& r2)
{
    int a = r1.getNum() * r2.getNum();
    int b = r1.getDen() * r2.getDen();
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads *
 * 
 * @param r rational
 * @param i int
 * @return Rational 
 */
Rational operator*(Rational& r, int i)
{
    int a = r.getNum() * i;
    int b = r.getDen();
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads *
 * 
 * @param i int
 * @param r rational
 * @return Rational 
 */
Rational operator*(int i, Rational& r)
{
    Rational ret = r * i;
    return ret;
}

/**
 * @brief Overloads /
 * 
 * @param r1 first rational
 * @param r2 second rational
 * @return Rational 
 */
Rational operator/(Rational& r1, Rational& r2)
{
    int a = r1.getNum() * r2.getDen();
    int b = r1.getDen() * r2.getNum();
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads /
 * 
 * @param r rational
 * @param i int
 * @return Rational 
 */
Rational operator/(Rational& r, int i)
{
    int a = r.getNum();
    int b = r.getDen() * i;
    Rational ret(a, b);
    ret.minTerm();
    return ret;
}
/**
 * @brief Overloads /
 * 
 * @param i int
 * @param r rational
 * @return Rational 
 */
Rational operator/(int i, Rational& r)
{
    Rational ret = r / i;
    return ret;
}

/**
 * @brief Overloads ==
 * 
 * @param r1 first rational
 * @param r2 second rational
 * @return true 
 * @return false 
 */
bool operator==(Rational& r1, Rational& r2)
{ return r1.getNum() == r2.getNum() && r1.getDen() == r2.getDen(); }
/**
 * @brief Overloads ==
 * 
 * @param r rational
 * @param i int
 * @return true 
 * @return false 
 */
bool operator==(Rational& r, int i)
{ return r.getNum() == i && r.getDen() == 1; }
/**
 * @brief Overloads ==
 * 
 * @param i int
 * @param r rational
 * @return true 
 * @return false 
 */
bool operator==(int i, Rational& r)
{ return r == i; }

/**
 * @brief Overloads !=
 * 
 * @param r1 first rational
 * @param r2 second rational
 * @return true 
 * @return false 
 */
bool operator!=(Rational& r1, Rational& r2)
{ return !(r1 == r2); }
/**
 * @brief Overloads !=
 * 
 * @param r rational
 * @param i int
 * @return true 
 * @return false 
 */
bool operator!=(Rational& r, int i)
{ return !(r == i); }
/**
 * @brief Overloads !=
 * 
 * @param i int
 * @param r rational
 * @return true 
 * @return false 
 */
bool operator!=(int i, Rational& r)
{ return !(r == i); }

int main()
{
    int n1 = 5;
    int n2 = 2;
    Rational a(n1, n2);
    Rational b = a;
    Rational c = n1;

    Rational s = a + b;
    Rational d = a - c;
    Rational m = a * b;
    Rational v = a / c;

    if (a == b)
        cout << "=" << endl;
    if (a != b)
        cout << "!" << endl;

    if (a == c)
        cout << "=" << endl;
    if (a != c)
        cout << "!" << endl;

    cout << a.toDouble() << endl;
    cout << b.toDouble() << endl;
    cout << c.toDouble() << endl;

    cout << s.getNum() << " & " << s.getDen() << endl;
    cout << s.toDouble() << endl;
    cout << d.getNum() << " & " << d.getDen() << endl;
    cout << d.toDouble() << endl;
    cout << m.getNum() << " & " << m.getDen() << endl;
    cout << m.toDouble() << endl;
    cout << v.getNum() << " & " << v.getDen() << endl;
    cout << v.toDouble() << endl;

    return 0;
}

/*
void Rational::minTerm()
{
    bool sign = false;
    if (num < 0)
    {
        num = 0 - num;
        sign = true;
    }
    if (num == den)
    {
        num = 1;
        den = 1;
    }
    else if (num < den)
        for (int i = 2; i <= num; i++)
            while (den % i == 0 && num % i == 0)
            {
                den /= i;
                num /= i;
            }
    else if (num > den)
        for (int i = 2; i <= den; i++)
            while (num % i == 0 && den % i == 0)
            {
                num /= i;
                den /= i;
            }
    if (sign)
        num = 0 - num;
}
*/