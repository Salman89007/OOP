#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string author;
    string title;
    int price;
};

void displayBook(Book b)
{
    cout << "Book's author : " << b.author << endl;
    cout << "Book's title : " << b.title << endl;
    cout << "Book's price : " << b.price << endl;
}

int main()
{
    Book b;
    cout << "enter author's name : " << endl;
    getline(cin, b.author);

    cout << "enter Book's title : " << endl;
    getline(cin, b.title);

    cout << "enter Book's Price : " << endl;
    cin >> b.price;

    displayBook(b);

    return 0;
}