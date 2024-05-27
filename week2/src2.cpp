#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
            if ((i * j) < 10)
            {
                cout << i << "X" << j << "=" << i * j << "  ";
            }
            else
            {
                cout << i << "X" << j << "=" << i * j << " ";
            }
		}
		cout << '\n';
	}


	return 0;
}