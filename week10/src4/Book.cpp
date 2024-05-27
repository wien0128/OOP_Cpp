#include "Book.h"
#include <cstring>

using namespace std;

Book::Book(const char* title, int price) : price(price)
{
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

Book::Book(const Book& book) : price(book.price)
{
    this->title = new char[strlen(book.title) + 1];
    strcpy(this->title, book.title);
}

Book::~Book()
{
    delete[] title;
}

void Book::set(const char* title, int price)
{
	this->price = price;
	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}