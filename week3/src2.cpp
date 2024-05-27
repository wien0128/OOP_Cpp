#include <iostream>

using namespace std;


bool average(int a[], int size, int& avg)
{
	if (a == nullptr || size <= 0)
	{
		cout << "파라미터 오류" << '\n';
		return false;
	}

	int sum{ 0 };
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}

	avg = sum / size;

	return true;
}

int main(void)
{
    int x[] = { 0, 1, 2, 3, 4, 5 };
    int avg;

    if (average(x, 6, avg))
    {
        cout << "평균은 " << avg << '\n';
    }

    if (average(x, 0, avg))
    {
        cout << "평균은 " << avg << '\n';
    }
    

    return 0;
}