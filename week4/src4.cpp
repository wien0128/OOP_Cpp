#include <iostream>

using namespace std;


template<typename T>
void reverseArray(T arr[], int size)
{
    for (int i = 0; i < size / 2; i++) 
    {
        T tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
}

int main() 
{
    int x[] = {1, 10, 100, 5, 4};

    reverseArray(x, 5);

    for(int i=0; i<5; i++)
        cout << x[i] << ' '; // 4 5 100 10 1 이 출력된다.

    cout << endl;


    return 0;
}