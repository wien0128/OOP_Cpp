#include <iostream>

using namespace std;


int main()
{
	char name[100], address[100];
	int age;

	cout << "이름: ";
	cin.getline(name, 101);

	cout << "주소: ";
	cin.getline(address, 101);

	cout << "나이: ";
	cin >> age;

	cout << "------------------------------------------------" << "\n";
	cout << name << ". " << address << ". " << age << '\n';

	return 0;
}