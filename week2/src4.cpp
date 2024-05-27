#include <iostream>

using namespace std;

int main()
{
	char c[100];
	int cnt{ 0 };

	cout << "문자들을 입력하라(100개 미만)." << endl;

	cin.getline(c, 101);

	for (int i = 0; i < 100; i++)
	{
		if (c[i] == 'x')
		{
			cnt++;
		}
	}

	cout << "x의 개수는 " << cnt << endl;

	return 0;
}