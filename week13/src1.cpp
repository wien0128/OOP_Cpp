#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(const string name) : name(name) {}
    virtual ~Shape() {}
    const string& getName() { return name; }
    virtual int getArea() = 0;
};

class Circle : public Shape {
    int radius;
public:
    Circle(const string name, int radius) : Shape(name), radius(radius) {}
    int getArea() override
    {
        return 3.14 * radius * radius;
    }
};

class Rect : public Shape {
    int width;
    int length;
public:
    Rect(const string name, int width, int length) : Shape(name), width(width), length(length) {}
    int getArea() override
    {
        return width * length;
    }
};

class Triangular : public Shape {
    int width;
    int length;
public:
    Triangular(const string name, int width, int length) : Shape(name), width(width), length(length) {}
    int getArea() override
    {
        return (width * length) / 2;
    }
};

int main()
{
    Shape *p[3];

    p[0] = new Circle("빈대떡", 10); // 이름, 반지름
    p[1] = new Rect("찰떡", 30, 40); // 이름, 너비, 높이
    p[2] = new Triangular("토스트", 30, 40); // 이름, 밑변, 높이

    for(int i=0; i<3; i++)
    {
        cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
    }
    
    for(int i=0; i<3; i++) 
        delete p[i];

    return 0;
}