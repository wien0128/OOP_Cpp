#include <iostream>

using namespace std;

class Int {
	int value;

public:
	Int(int in = 0) : value(in) {}
	void set(int in);
	int get() const;
};

void Int::set(int in)
{
	value = in;
}

int Int::get() const
{
	return value;
}

int main()
{
	Int i1 = 20;
	const Int i2 = i1;
	i1.set(10);

	cout << i1.get() << ", " << i2.get() << "\n";

	return 0;
}
