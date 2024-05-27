#include <iostream>

using namespace std;


double biggest(double arr[], int n)
{
	double max{ 0.0 };

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int main()
{
	double arr[5];

	cout << "5개의 실수를 입력하라>> ";
	
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}

	cout << "제일 큰 수 = " << biggest(arr, 5) << endl;


	return 0;
}