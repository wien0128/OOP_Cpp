#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    vector<string> names;

    cout << "이름을 5개 입력하라\n";
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ">> ";
        getline(cin, str);
        names.push_back(str);
    }

    sort(names.begin(), names.end());

    cout << "사전에서 가장 뒤에 나오는 이름은 " << names.back() << '\n';

    return 0;
}
