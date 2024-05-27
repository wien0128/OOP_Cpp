#include <iostream>
#include <algorithm>

using namespace std;

int big(int a, int b)
{
    return a > b ? a : b;
}

int big(int a, int b, int c)
{
    return max({a, b, c});
}

int main(void)
{
    int x = big(3, 5);
    int y = big(300, 60);
    int z = big(30, 60, 50);

    cout << x << ' ' << y << ' ' << z << '\n';

    return 0;
}