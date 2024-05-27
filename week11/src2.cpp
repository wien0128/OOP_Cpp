#include <iostream>
#include <string>

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

    bool operator==(int op2)
    {
        return price == op2 ? true : false;
    }

    bool operator==(string op2)
    {
        return title.compare(op2) ? false : true;
    }

    bool operator==(Book op2)
    {
        if (title == op2.title && price == op2.price && pages == op2.pages)
            return true;
        return false;
    }
};


int main()
{
    Book a("명품 C++", 30000, 500), b("고품격 C++", 30000, 500);

    if (a == 30000) cout << "정가 30000원" << "\n";

    if (a == "명품 C++") cout << "명품 C++입니다." << '\n';

    if (a == b) cout << "두 책이 같은 책입니다." << '\n';


    return 0;
}