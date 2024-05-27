#include <iostream>

using namespace std;

void f(char c = ' ', int line = 1)
{
    for (int i = 0; i < line; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << c;
        }
        cout << '\n';
    }
    
}

int main(void)
{
    f();
    f('%');
    f('@', 5);

    return 0;
}