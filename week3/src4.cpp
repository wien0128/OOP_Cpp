#include <iostream>

using namespace std;

char& find(char a[], char c, bool& success)
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == c)
		{
			success = true;
			return a[i];
		}
	}
	success = false;

	return a[0];
}

int main(void)
{
    char s[] = "Mike";
    bool b = false;
    char& loc = find(s, 'M', b);

    if (!b)
    {
        cout << "M을 발견할 수 없다." << "\n";
        return 0;
    }
    loc = 'm';
    cout << s << "\n";
    

    return 0;
}