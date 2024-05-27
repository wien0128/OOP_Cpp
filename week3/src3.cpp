#include <iostream>

using namespace std;


bool bigger(int a, int b, int& big)
{
    big = a > b ? a : b;
    return a == b;
}

int main(void)
{
    int x, y, big;
    bool b;

    cout << "두 정수를 입력하세요>> ";
    cin >> x >> y;

    b = bigger(x, y, big);

    if (b)
    {
        cout << "Same" << '\n';
    }
    else
    {
        cout << "큰 수는 " << big << '\n';
    }
    

    return 0;
}