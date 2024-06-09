#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;

class Book {
    string title;
    int price;
    int pages;
public:
    Book(const string& title = string(), int price = 0, int pages = 0) 
    {
        this->title = title;
        this->price = price;
        this->pages = pages;
    }

    void show() const
    {
        cout << title << ' ' << price << "원 " << pages << " 페이지" << "\n";
    }

    const string& getTitle() const
    {
        return title;
    }

    bool operator!();
    Book& operator++();
    Book& operator++(int);
    friend ostream& operator<<(ostream& op1, Book op2);
};

#endif