#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    double price;
};

void displayBook(Book b)
{
    cout << "\nBook Details:" << endl;
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Price: " << b.price << endl;
}

int main()
{
    Book b;

    cout << "Enter book title: ";
    getline(cin , b.title);
   

    cout << "Enter author name: ";
    getline(cin, b.author);
   

    cout << "Enter book price: ";
    cin >> b.price;

    displayBook(b);

    return 0;
}