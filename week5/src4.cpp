#include <iostream>
#include <string>

using namespace std;


void replaceStr(string& str, const string& find, const string& replace)
{
    if (find.empty()) return;

    size_t pos = 0;

    while ((pos = str.find(find, pos)) != string::npos)
    {
        str.replace(pos, find.length(), replace);
        pos += replace.length();
    }
}

int main()
{
    string str;
    cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << "\n";
    getline(cin, str, '&');
    cin.ignore();

    string find, replace;

    cout << "찾을 단어: ";
    getline(cin, find);

    cout << "대치할 단어: ";
    getline(cin, replace);

    replaceStr(str, find, replace);

    cout << str << "\n";


    return 0;
}