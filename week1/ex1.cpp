#include <iostream>

using namespace std;

int main(void) 
{   
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        puts("\n");
    }


    return 0;
}