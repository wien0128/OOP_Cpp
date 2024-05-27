#ifndef BOOk_H
#define BOOK_H

#include <iostream>

class Book {
    char *title;
    int price;
public:
    Book(const char* title, int price);
    Book(const Book& Book);
    ~Book();
    void set(const char* title, int price);
    void show() const { std::cout << title << ' ' << price << "원" << std::endl; }
};

#endif