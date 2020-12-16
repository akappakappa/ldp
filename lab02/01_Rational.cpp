/**
 * @file 01_Rational.cpp
 * @author github.com/akappakappa
 * @brief Rational object that stores number in num and den
 * @date 2020-10-21
 * 
 * Design and implement a rational number class, Rational. A rational number has two parts: \n
 * a numerator and a denominator, for example 5/6 (five-sixths, also known as approximately 0.83333). \n
 * Look up the definition if you need to. \n
 * Provide assignment, addition, subtraction, multiplication, division and equality operators. \n
 * Also, provide a conversion to double.
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

int Rational::getNum()
{ return num; }

int Rational::getDen()
{ return den; }

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