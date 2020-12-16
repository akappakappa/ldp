/**
 * @file 02_Book.cpp
 * @author github.com/akappakappa
 * @brief Book object that stores book data
 * @date 2020-10-14
 * 
 * Design and implement a Book class similar to the one you would find in a software developed for a library. \n
 * Class Book should have members for the ISBN, title, author and copyright date. \n
 * Also store data on whether or not the book has been checked out. Do the following: \n
 * 1. Create functions for returning those data values. \n
 * 2. Create a function for creating a new book (constructor). \n
 * 3. Create functions for checking books in and out. \n
 * 4. Do simple validation of data entered into a Book; \n
 *    for example accept ISBNs only of the form n-n-n-x where n is an integer and x is a digit or a letter. \n
 *    Store an ISBN as a string. \n
 * 5. Implement the == operator that checks whether the ISBN numbers are the same for two books. \n
 * 6. Have != also compare the ISBN numbers. \n
 * 7. Have a << operator print out the title, author and ISBN on separate lines.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @class Book
 * @brief Object containing book data
 * 
 */
class Book
{
    public:
        /**
         * @brief Construct a new Book object
         * 
         * @param i isbn
         * @param t title
         * @param a author
         * @param d copyright date
         */
        Book(string i, string t, string a, int d);
        /**
         * @brief Allows to check in / out book
         * 
         */
        void check();
        /**
         * @brief Get the Isbn
         * 
         * @return string 
         */
        string getIsbn();
        /**
         * @brief Get the Title
         * 
         * @return string 
         */
        string getTitle();
        /**
         * @brief Get the Author
         * 
         * @return string 
         */
        string getAuthor();
        /**
         * @brief Get the Date
         * 
         * @return int 
         */
        int getDate();
        /**
         * @brief Book's checkout status
         * 
         * @return true if out
         * @return false otherwise
         */
        bool isOut();
        /**
         * @brief Checks if 2 books are identical, via isbn comparison
         * 
         * @param other other to compare
         * @return true if identical
         * @return false otherwise
         */
        bool operator==(Book& other);
        /**
         * @brief Checks if 2 books are different, via isbn comparison
         * 
         * @param other other to compare
         * @return true if identical
         * @return false otherwise
         */
        bool operator!=(Book& other);

    private:
        string isbn;
        string title;
        string author;
        int date;
        bool outStatus;
};

Book::Book(string i, string t, string a, int d)
    : isbn{i}, title{t}, author{a}, date{d}, outStatus{false}
{}

void Book::check()
{
    if (!outStatus)
        outStatus = true;
    else if (outStatus)
        outStatus = false;
}

string Book::getIsbn()
{ return isbn; }

string Book::getTitle()
{ return title; }

string Book::getAuthor()
{ return author; }

int Book::getDate()
{ return date; }

bool Book::isOut()
{ return outStatus; }

/**
 * @brief Checks validity of isbn
 * 
 * @param i isgn
 * @return true if in the form nnnn-nnnn-nnnn-x
 * @return false otherwise
 */
bool isbnOk(string& i)
{
    // n n n n - n n n n - n n n n - x : ISBN
    // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 : ISBN[j]
    if (i.length() != 16)
        return false;
    for (int j = 0; j < 16; j++)
    {
        if ((j >= 0 && j <= 3) || (j >= 5 && j <= 8) || (j >= 10 && j <= 13))
            if (i[j] < 48 || i[j] > 57)     //numeri
                return false;
        else if (j == 4 || j == 9 || j == 14)
            if (i[j] != '-')
                return false;
        else if (j == 15)
            if ((i[j] < 48 || i[j] > 57) && // numeri
                (i[j] < 65 || i[j] > 90) && // maiuscole
                (i[j] < 97 || i[j] > 122))  // minuscole
                return false;
    }
    return true;
}

/**
 * @brief Checks validity of author
 * 
 * @param a author
 * @return true if only letters
 * @return false otherwise
 */
bool authorOk(string& a)
{
    for (int i = 0; i < a.length(); i++)
        if ((a[i] < 65 || a[i] > 90) && (a[i] < 97 || a[i] > 122)) // maiuscole e minuscole
            return false;
    return true;
}

/**
 * @brief Checks validity of date
 * 
 * @param d date
 * @return true if 0 <= date <= 2020
 * @return false otherwise
 */
bool dateOk(int d)
{
    return (d >= 0 || d <= 2020);
}

bool Book::operator==(Book& other)
{ return isbn == other.getIsbn(); }

bool Book::operator!=(Book& other)
{ return !(*this == other); }

/**
 * @brief Outputs Book data
 * 
 * @param os output stream
 * @param b Book object
 * @return ostream& well formatted output
 */
ostream& operator<<(ostream& os, Book& b)
{ return os << b.getTitle() << endl << b.getAuthor() << endl << b.getIsbn() << endl; }

int main()
{
    string isbn1;
    string title1;
    string author1;
    int date1;
    // isbn
    do
    {
        cout << "> Insert ISBN: ";
        cin >> isbn1;
        if (!isbnOk(isbn1))
            cout << "** ISBN not valid**" << endl;
    } while (!isbnOk(isbn1));
    // title
    cout << "> Insert title: ";
    cin >> title1;
    // author
    do
    {
        cout << "> Insert author: ";
        cin >> author1;
        if (!authorOk(author1))
            cout << "** Author not valid **" << endl;
    } while (!authorOk(author1));
    // date
    do
    {
        cout << "> Insert date: ";
        cin >> date1;
        if (!dateOk(date1))
            cout << "** Date not valid **" << endl;
    } while (!dateOk(date1));
    Book b1 = Book(isbn1, title1, author1, date1);
    cout << b1;

    //-----------------------------------------------//

    string isbn2;
    string title2;
    string author2;
    int date2;
    // isbn
    do
    {
        cout << "> Insert ISBN: ";
        cin >> isbn2;
        if (!isbnOk(isbn2))
            cout << "** ISBN not valid**" << endl;
    } while (!isbnOk(isbn2));
    // title
    cout << "> Insert title: ";
    cin >> title2;
    // author
    do
    {
        cout << "> Insert author: ";
        cin >> author2;
        if (!authorOk(author2))
            cout << "** Author not valid **" << endl;
    } while (!authorOk(author2));
    // date
    do
    {
        cout << "> Insert date: ";
        cin >> date2;
        if (!dateOk(date2))
            cout << "** Date not valid **" << endl;
    } while (!dateOk(date2));
    Book b2 = Book(isbn2, title2, author2, date2);
    cout << b2;

    //-----------------------------------------------//

    if (b1 == b2)
        cout << "stonks!" << endl;
    else if (b1 != b2)
        cout << "not stonks :(" << endl;

    //-----------------------------------------------//

    if (b1.isOut())
        cout << "out" << endl;
    else
        cout << "in" << endl;
    b1.check();
    if (b1.isOut())
        cout << "out" << endl;
    else
        cout << "in" << endl;

    return 0;
}   