#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	char password1[100], password2[100];

	cout << "새 암호를 입력하세요>> ";
	cin >> password1;

	cin.clear();
	
	cout << "새 암호를 다시 한번 입력하세요>> ";
	cin >> password2;

	if (strcmp(password1, password2))
	{
		cout << "같지 않습니다.";
	}
	else
	{
		cout << "같습니다.";
	}


	return 0;
}