#include <iostream>
#include <algorithm>

using namespace std;

int big(int a, int b, int c = INT_MIN)
{
    return max({a, b, c});
}

int main(void)
{
    int x = big(-2, -1);
    int y = big(300, 60);
    int z = big(-1, -1, 0);

    cout << x << ' ' << y << ' ' << z << '\n';

    return 0;
}