#include "Book.h"


ostream& operator<<(ostream& op1, Book op2)
{
    op1 << "책이름: " << op2.title << ", "
        << "가격: " << op2.price << ", "
        << "페이지수: " << op2.pages << ", ";
    return op1;
}

int main()
{
    Book book1("벼룩시장", 0, 50), book2("C++", 10000, 1000);
    
    if (!book1) cout << "공짜다" << "\n";

    cout << ++book2 << "\n";
    cout << book2++ << "\n";
    cout << book2 << "\n";


    return 0;
}
