#include "Book.h"

bool Book::operator!()
{
    return (price == 0) ? true : false;
}

Book& Book::operator++()
{
    price += price * 0.1;
    return *this;
}

Book& Book::operator++(int)
{
    Book tmp = *this;
    price += price * 0.1;
    return tmp;
}