#include <iostream>
#include <algorithm>
#include "Vector.h"
#include "String.h"


using namespace std;

void test_string() {
    const char *str1 = "cat";
    String str2 = str1;
    const char *str3 = "dog";
    String str4 = str3;

    cout << "** Test 1: operator[] ** " << endl;
    for (auto i = 0; i < str2.size(); i++) cout << "str2[" << i << "]: " << str2[i] << endl;
    str2[0] = 'C';
    cout << "str2[0] = \'C\'를 수행한 후, str2: " << str2 << endl << endl;

    cout << "** Test 2: 대입 연산자 **" << endl;
    str4 = "Super";
    cout << "str4 = \"Super\"를 수행한 후, str4: " << str4 << endl;
    (str4 += " ") += String("man");
    cout << "(str4 += \" \") += String(\"man\")를 수행한 후, str4: " << str4 << endl;
    str4 = String("Elephant");
    cout << "str4 = String(\"Elephant\")를 수행한 후, str4: " << str4 << endl << endl;

    cout << "** Test 3: operator+ **" << endl;
    cout << "str3 + str2: " << str3 + str2 << endl;
    cout << "str2 + str1: " << str2 + str1 << endl;
    cout << "str2 + str4: " << str2 + str4 << endl << endl;

    cout << "** Test 4: 비교 연산자 **" << endl;
    cout << str2 << " == " << str1 << ": " << (str2 == str1 ? "true" : "false") << endl;
    cout << str2 << " != " << str1 << ": " << (str2 != str1 ? "true" : "false") << endl;
    cout << str1 << " == " << str2 << ": " << (str1 == str2 ? "true" : "false") << endl;
    cout << str1 << " != " << str2 << ": " << (str1 != str2 ? "true" : "false") << endl;
    cout << str4 << " == " << str1 << ": " << (str4 == str1 ? "true" : "false") << endl;
    cout << str4 << " != " << str2 << ": " << (str4 != str2 ? "true" : "false") << endl;
    cout << str1 << " > " << str4 << " : " << (str1 > str4 ? "true" : "false") << endl;
    cout << str4 << " > " << str1 << " : " << (str4 > str1 ? "true" : "false") << endl;
    cout << str2 << " > " << str4 << " : " << (str2 > str4 ? "true" : "false") << endl;
    cout << str4 << " > " << str2 << " : " << (str4 > str1 ? "true" : "false") << endl;
    cout << str1 << " >= " << str4 << " : " << (str1 >= str4 ? "true" : "false") << endl;
    cout << str4 << " >= " << str1 << " : " << (str4 >= str1 ? "true" : "false") << endl;
    cout << str2 << " >= " << str4 << " : " << (str2 >= str4 ? "true" : "false") << endl;
    cout << str4 << " >= " << str2 << " : " << (str4 >= str1 ? "true" : "false") << endl;
    cout << str1 << " < " << str4 << " : " << (str1 < str4 ? "true" : "false") << endl;
    cout << str4 << " < " << str1 << " : " << (str4 < str1 ? "true" : "false") << endl;
    cout << str2 << " < " << str4 << " : " << (str2 < str4 ? "true" : "false") << endl;
    cout << str4 << " < " << str2 << " : " << (str4 < str1 ? "true" : "false") << endl;
    cout << str1 << " <= " << str4 << " : " << (str1 <= str4 ? "true" : "false") << endl;
    cout << str4 << " <= " << str1 << " : " << (str4 <= str1 ? "true" : "false") << endl;
    cout << str2 << " <= " << str4 << " : " << (str2 <= str4 ? "true" : "false") << endl;
    cout << str4 << " <= " << str2 << " : " << (str4 <= str1 ? "true" : "false") << endl << endl;
}

void test_vector() {
    String arr1[5] = {
            String("Melon"),
            String("Water Melon"),
            String("Cherry"),
            String("Apple"),
            String("Banana")
    };
    String arr2[3] = {
            String("Orange"),
            String("Graph"),
            String("Mango")
    };
    Vector<String> v1(3, "A");
    Vector<String> v2(arr1, 5);
    Vector<String> v3(arr2, 3);
    Vector<String> v4(3);
    for (auto i = 0; i < 3; i++) v4.push_back(arr2[i].tolower());

    cout << "** Test 1: ostream << **" << endl;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;
    cout << "v4: " << v4 << endl << endl;

    cout << "** Test 2: 대입 연산자 **" << endl;
    v1 = v2;
    cout << "v1 = v2 수행 후, v1: " << v1 << endl;
    v1 += v3;
    cout << "v1 += v3 수행 후, v1: " << v1 << endl;

    cout << "** Test 3: operator[] **" << endl;
    for (auto i = 0; i < v1.size(); i++) cout << "v1[" << i << "] :" << v1[i] << endl;
    v1[1] = "Pear";
    cout << "v1[1] = \"Pear\"를 수행한 후, v[1]: " << v1[1] << endl << endl;

    cout << "** Test 4: operator+ **" << endl;
    cout << "v1 + v2: " << v1 + v2 << endl << endl;

    cout << "** Test 5: 비교 연산자 **" << endl;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;
    cout << "v4: " << v4 << endl;
    cout << "v1 == v2: " << (v1 == v2 ? "true" : "false") << endl;
    cout << "v3 == v4: " << (v3 == v4 ? "true" : "false") << endl;
    cout << "v1 != v2: " << (v1 != v2 ? "true" : "false") << endl;
    cout << "v3 != v4: " << (v3 != v4 ? "true" : "false") << endl << endl;

    cout << "** Test 6: 정렬 **" << endl;
    cout << "정렬 전 v1: " << v1 << endl;
    sort(v1.begin(), v1.end());
    cout << "정렬 후 v1: " << v1 << endl;
}

int main() {
    cout << ":::::::::: Test String ::::::::::" << endl;
    test_string();

    cout << "\n:::::::::: Test Vector ::::::::::" << endl;
    test_vector();
}
