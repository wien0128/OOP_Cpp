#include <iostream>

using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { setColor(r, g, b); }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() const { cout << red << " " << green << " " << blue << "\n"; }
};

int main()
{
	Color screenColor(255, 0, 0);
	Color* p = nullptr;

	p = &screenColor;	// 1
	(*p).show();		// 2
	Color colors[3];	// 3
	p = &colors[0];		// 4

	(*p).setColor(255, 0, 0);	// 5
	p[1].setColor(0, 255, 0);	// 5
	p[2].setColor(0, 0, 255);	// 5

	for (int i = 0; i < 3; i++)     // 6
	{
		p[i].show();
	}

	return 0;
}
