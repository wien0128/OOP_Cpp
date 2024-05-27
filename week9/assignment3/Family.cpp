#include "Family.h"
#include <iostream>

using namespace std;

Family::Family(const string& name, int size) : name(name), size(size)
{
	this->p = new Person[size];
}

Family::~Family()
{
	delete[] p;
}

void Family::setName(int index, const string& name)
{
	p[index].setName(name);
}

void Family::show() const
{
	cout << name << "가족은 다음과 같이 3명입니다.\n";
	for (int i = 0; i < size; i++)
	{
        if (size - i != 1)
        {
            cout << p[i].getName() << ", ";
        }
		cout << p[i].getName();
	}
	cout << "\n";
}