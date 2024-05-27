#include <iostream>
#include <string>

using namespace std;


int main()
{
	string names[5];
	string str;

	for (int i = 0; i < 5; i++)
	{
		cout << "이름>> ";
		getline(cin, names[i]);
		if (i == 0 || str < names[i])
		{
			str = names[i];
		}
	}
	
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << str << '\n';

	return 0;
}