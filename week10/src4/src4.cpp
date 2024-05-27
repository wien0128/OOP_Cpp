#include "Book.h"

using namespace std;

int main()
{
    Book cpp("C++", 10000);
    Book java = cpp;
    cpp.show();
    java.show();
    java.set("Java", 12000);
    cpp.show();
    java.show();


    return 0;
}