#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, string> dic;

    // 단어 3개를 map에 저장
    dic.insert({"love", "사랑"}); // ("love", "사랑") 저장
    dic.insert({"apple", "사과"}); // ("apple", "사과") 저장
    dic["cherry"] = "체리"; // ("cherry", "체리") 저장

    cout << "저장된 단어 개수 " << dic.size() << endl;

    string eng;
    while (true)
    {
        cout << "찾고 싶은 단어>> ";
        cin >> eng;// 사용자로부터 키 입력

        if (eng == "exit")
            break; // "exit"이 입력되면 종료
            
        if(dic.count(eng) == 0) // eng '키'를 끝까지 찾았는데 없음
            cout << "없음" << endl;
        else
            cout << dic[eng] << endl; // dic에서 eng의 값을 찾아 출력
    }
    cout << "종료합니다..." << endl;
    
    return 0;
}