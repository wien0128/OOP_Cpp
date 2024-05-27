#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea() const;
};

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

double Circle::getArea() const
{
	return radius * radius * 3.14;
}

int main()
{
	Circle circles[3];
	int cnt{ 0 };

	for (int i = 0; i < 3; i++)
	{
		int tmp;

		cout << "원 " << i + 1 << "의 반지름>> ";
		cin >> tmp;
		circles[i].setRadius(tmp);

		if (circles[i].getArea() > 100)
		{
			cnt++;
		}
	}

	cout << "면적이 100보다 큰 원은 " << cnt << "개입니다." << "\n";

	return 0;
}
