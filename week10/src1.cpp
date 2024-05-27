#include <iostream>

using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int radius) { this->radius = radius; }
    double getArea() const { return 3.14 * radius * radius; }
};

void swap(Circle& A, Circle& B)
{
    Circle tmp = A;
    A = B;
    B = tmp;
}

int main()
{
    Circle A;
    Circle B(3);

    cout << "A의 면적 = " << A.getArea() << ", " << "B의 면적 = " << B.getArea() << endl;
    swap(A, B); // swap 함수 구현
    cout << "A의 면적 = " << A.getArea() << ", " << "B의 면적 = " << B.getArea() << endl;


    return 0;
}