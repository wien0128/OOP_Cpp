#include <iostream>
#include <string>

using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 1) : radius(radius) {}
    void setRadius(int radius) { this->radius = radius; }
    int getRadius() const { return radius; }
    double getArea() const { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle{
    string name;
public:
    NamedCircle(const string& name = "", int radius = 1) : Circle(radius), name(name) {}
    const string& getName() const
    {
        return name;
    }
    void show() const
    {
        cout << "반지름이 " << this->getRadius() << "인 " << this->name << "\n";
    }
    friend iostream& operator>>(iostream& op1, NamedCircle& op2);
};

iostream& operator>>(iostream& op1, NamedCircle& op2)
{
    int size;
    string name;
    op1 >> size >> op2.name;
    op2.setRadius(size);
    return op1;
}

int main()
{
    const int NUM_OF_PIZZA = 5;
    NamedCircle pizza[NUM_OF_PIZZA];

    for (int i = 0; i < NUM_OF_PIZZA; ++i)
    {
        cin >> pizza;
    }
    
}