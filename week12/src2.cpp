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

    friend istream& operator>>(istream& in, NamedCircle& op2);
};

istream& operator>>(istream& in, NamedCircle& op2)
{
    int size;
    string name;
    in >> size >> name;

    op2.setRadius(size);
    op2.name = name;
    
    return in;
}

int main()
{
    const int NUM_OF_PIZZA = 5;
    NamedCircle pizza[NUM_OF_PIZZA];
    NamedCircle maxPizza;

    cout << "5개의 피자 반지름과 피자 이름을 입력하세요.\n";
    for (int i = 0; i < NUM_OF_PIZZA; ++i)
    {
        cout << i + 1 << " >> "; 
        cin >> pizza[i];
        maxPizza = (pizza[i].getArea() > maxPizza.getArea()) ? pizza[i] : maxPizza; 
    }
    
    NamedCircle* largestPizza = &pizza[0];
    for (int i = 1; i < NUM_OF_PIZZA; ++i)
    {
        if (pizza[i].getArea() > largestPizza->getArea())
        {
            largestPizza = &pizza[i];
        }
    }
    
    cout << "가장 면적이 큰 피자는 " << largestPizza->getName() << "입니다\n";
    cout << "가장 면적이 큰 피자는 " << maxPizza.getName() << "입니다\n";

    return 0;
}