/**
 * @file main.cpp
 * @author Andrea Valentinuzzi matr1219617
 * @brief Tester for the LaserScannerDriver class.
 * @date 2020-12-01
 * 
 * @see LaserScannerDriver
 */

#include "LaserScannerDriver.hpp"
using namespace std;

int main()
{
    double res = 1;
    cout << endl;

    /* Testing constructor */
    LaserScannerDriver s1(res);

    try { LaserScannerDriver err1(0.01); }
    catch(const exception& e)
    { cerr << "    * 1. error caught @constructor : " << e.what() << endl; }
    try { LaserScannerDriver err2(1.01); }
    catch(const exception& e)
    { cerr << "    * 2. error caught @constructor : " << e.what() << endl; }

    cout << "    > s1 constructed\n" << endl;


    /* Testing new_scan() */
    vector<double> v1(170, 36);
    vector<double> v2(190, 24);
    
    s1.new_scan(v1);
    s1.new_scan(v2);

    try { vector<double> err3(180, -0.1); s1.new_scan(err3); }
    catch(const exception& e)
    { cerr << "    * 3. error caught @new_scan : " << e.what() << endl; }
    
    cout << "    > v1 && v2 added to s1\n" << endl;


    /* Testing get_distance() */
    vector<double> v3{0, 1, 2, 3, 4, 5};
    s1.new_scan(v3);
    cout << s1.get_distance(0) << endl;
    cout << s1.get_distance(180) << endl;
    cout << s1.get_distance(3.1) << endl;
    cout << s1.get_distance(3.9) << endl;

    cout << endl;
    try { cout << s1.get_distance(-0.1) << endl; }
    catch(const exception& e)
    { cerr << "    * 4. error caught @get_distance : " << e.what() << endl; }
    try { cout << s1.get_distance(180.1) << endl; }
    catch(const exception& e)
    { cerr << "    * 5. error caught @get_distance : " << e.what() << endl; }

    cout << "    > v3 {0, 1, 2, 3, 4, 5} added: testing angles 0, 180, 3.1, 3.9\n" << endl;


    /* Testing get_scan() */
    s1.new_scan(v2);
    vector<double> p = s1.get_scan();
    for (int i = 0; i < p.size(); i++)
        cout << p.at(i) << " ";
    cout << endl << endl;
    cout << "    > v2 added and removed, printing it\n" << endl;

    /* Testing new_scan() with full buffer (limit case) */
    for (int i = 0; i < 10; i++)
        s1.new_scan(v2);
    s1.new_scan(v2);
    for (int i = 0; i < 10; i++)
        p = s1.get_scan();

    try { p = s1.get_scan(); }
    catch(const exception& e)
    { cerr << "    * 6. error caught @get_distance : " << e.what() << endl; }
    try { p = s1.get_scan(); }
    catch(const exception& e)
    { cerr << "    * 7. error caught @get_scan : " << e.what() << endl; }

    cout << "    > v2 added 10 times (over limit) and removed 10 times -> empty buffer\n" << endl;


    /* Testing clear_buffer() */
    s1.new_scan(v1);
    s1.clear_buffer();

    cout << "    > v1 added and buffer cleared\n" << endl;


    /* Testing operator<<() */
    s1.new_scan(v2);
    cout << s1 << endl;

    cout << endl;
    try { s1.clear_buffer(); cout << s1 << endl; }
    catch(const exception& e)
    { cerr << "    * 8. error caught @operator<< : " << e.what() << endl; }

    cout << "    > v1 added and operator<< tested\n" << endl;

    /* Testing copy/move constructor/assignment */
    LaserScannerDriver s2(s1);
    cout << "    > copy constructor OK\n" << endl;
    LaserScannerDriver s3;
    LaserScannerDriver s4;
    cout << "    > default constructor OK\n" << endl;
    LaserScannerDriver s5m(s1);
    LaserScannerDriver s5(move(s5m));
    cout << "    > move constructor OK\n" << endl;
    s3 = s1;
    cout << "    > copy assignment OK\n" << endl;
    LaserScannerDriver s4m(s1);
    s4 = move(s4m);
    cout << "    > move assignment OK\n" << endl;

    LaserScannerDriver f1(f1);
    LaserScannerDriver f2(move(f2));
    f1 = f1;
    f2 = move(f2);
    cout << "    > self reference limit cases OK\n" << endl;

    s1.new_scan(v1);
    cout << s1.get_distance(90) << endl;
    s2.new_scan(v1);
    cout << s2.get_distance(90) << endl;
    s3.new_scan(v1);
    cout << s3.get_distance(90) << endl;
    s4.new_scan(v1);
    cout << s4.get_distance(90) << endl;
    s5.new_scan(v1);
    cout << s5.get_distance(90) << endl;

    cout << endl;
    cout << "    > all new scanner objects tested" << endl;


    cout << endl;
    cout << "    ---- EVERYTHING TESTED AND WORKING CORRECTLY ----" << endl;
    cout << endl;

    return 0;
}


/* EXPECTED NUMBERS

0
0
3
4
36 ... (170) ... 36 10 ... (10) ... 10
24 ... (170) ... 24 10 ... (10) ... 10
36
36
36
36
36

*/


/* EXPECTED CONSOLE OUTPUT

    * 1. error caught @constructor : ** Resolution must be between 0.1 and 1 **       
    * 2. error caught @constructor : ** Resolution must be between 0.1 and 1 **       
    > s1 constructed

    * 3. error caught @new_scan : ** One or more elements of the vector are invalid **
    > v1 && v2 added to s1

0
0
3
4

    * 4. error caught @get_distance : ** Angle must be between 0 and 180 **
    * 5. error caught @get_distance : ** Angle must be between 0 and 180 **
    > v3 {0, 1, 2, 3, 4, 5} added: testing angles 0, 180, 3.1, 3.9

36 ... (170) ... 36 10 ... (10) ... 10

    > v2 added and removed, printing it

    * 6. error caught @get_distance : ** Buffer is empty **
    * 7. error caught @get_scan : ** Buffer is empty **
    > v2 added 10 times (over limit) and removed 10 times -> empty buffer

    > v1 added and buffer cleared

24 ... (170) ... 24 10 ... (10) ... 10

    * 8. error caught @operator<< : ** Buffer is empty **
    > v1 added and operator<< tested

    > copy constructor OK

    > default constructor OK

    > move constructor OK

    > copy assignment OK

    > move assignment OK

    > self reference limit cases OK

36
36
36
36
36

    > all new scanner objects tested

    ---- EVERYTHING TESTED AND WORKING CORRECTLY ----

*/


/* TESTED FUNCTIONS

>    LaserScannerDriver(double r);
>    LaserScannerDriver() : LaserScannerDriver(1) {}
>    LaserScannerDriver(const LaserScannerDriver &lsd);
>    LaserScannerDriver(LaserScannerDriver &&lsd);
>    LaserScannerDriver &operator=(const LaserScannerDriver &lsd);
>    LaserScannerDriver &operator=(LaserScannerDriver &&lsd);
>    ~LaserScannerDriver();

>    void new_scan(const std::vector<double> &v);
>    std::vector<double> get_scan();
>    void clear_buffer();
>    double get_distance(double a) const;

>    std::vector<double> get_last_scan() const;
>    std::ostream &operator<<(std::ostream &os, const LaserScannerDriver &lsd);

*/


/* VALGRIND OUTPUT

=
=    HEAP SUMMARY:
=        in use at exit: 0 bytes in 0 blocks
=      total heap usage: 64 allocs, 64 frees, 129,081 bytes allocated
=
=    All heap blocks were freed -- no leaks are possible
=
=    ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/