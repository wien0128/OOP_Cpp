#include <iostream>

using namespace std;

class Rectangle {
	int width;
	int height;
public:

	Rectangle() : width(1), height(1) {}

	Rectangle(int wh) : width(wh), height(wh) {}
	
	Rectangle(int w, int h) : width(w), height(h) {}

	bool isSquare();
};

bool Rectangle::isSquare()
{
	return width == height;
}

int main()
{
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << "\n";
	if (rect2.isSquare()) cout << "rect2은 정사각형이다." << "\n";
	if (rect3.isSquare()) cout << "rect3은 정사각형이다." << "\n";

	return 0;
}
