#include <algorithm>
#include <cstring>
#include <cctype>
#include "String.h"

const unsigned String::npos = 0xFFFFFFFF;

String::String(unsigned capacity) : memory(nullptr), capacity(capacity) {
    this->memory = allocate(this->capacity);
    strcpy(this->memory, "");
}

String::String(const char *str) : memory(nullptr), capacity(strlen(str) + 1) {
    this->memory = allocate(this->capacity);
    strcpy(this->memory, str);
}

String::String(const String &str) : memory(nullptr), capacity(str.length() + 1) {
    this->memory = allocate(this->capacity);
    strcpy(this->memory, str.memory);
}

String::~String() { delete[] this->memory; }

void String::set(const char *str) {
    unsigned len = strlen(str);
    unsigned cap = len + 1;
    if (cap > this->capacity) {
        char *mem = allocate(cap);
        delete[] this->memory;
        this->memory = mem;
        this->capacity = cap;
    }
    strcpy(this->memory, str);
}

void String::set(const String &str) { this->set(str.memory); }

unsigned String::length() const { return strlen(this->memory); }

unsigned String::size() const { return strlen(this->memory); }

String String::substr(unsigned start, unsigned length) const {
    check_index(start);
    String s(length + 1);
    strncpy(s.memory, this->memory + start, length);
    return s;
}

void String::insert(unsigned index, const char *str) {
    check_index(index);
    unsigned len = this->length() + strlen(str);
    unsigned cap = len + 1;
    char *mem = allocate(cap);
    strncpy(mem, this->memory, index);
    strcat(mem, str);
    strcat(mem, this->memory + index);
    if (this->capacity < cap) {
        delete[] this->memory;
        this->memory = mem;
    } else {
        strcpy(this->memory, mem);
        delete[] mem;
        this->capacity = cap;
    }
}

void String::insert(unsigned index, const String &str) {
    this->insert(index, str.memory);
}

void String::erase(unsigned start, unsigned length) {
    this->check_index(start);
    unsigned len = this->size() - length;
    char *dest = new char[len + 1];
    strncpy(dest, this->memory, start);
    strcat(dest, this->memory + start + length);
    strcpy(this->memory, dest);
    delete[] dest;
}

void String::replace(unsigned start, unsigned length, const char *str) {
    this->erase(start, length);
    this->insert(start, str);
}

void String::replace(unsigned start, unsigned length, const String &str) {
    this->erase(start, length);
    this->insert(start, str);
}

unsigned String::find(const char *str, unsigned pos) const {
    char *p = strstr(this->memory + pos, str);
    if (p == nullptr) return String::npos;
    return p - this->memory;
}

unsigned String::find(const String &str, unsigned pos) const {
    return find(str.memory, pos);
}

String String::tolower() const {
    String ret = *this;
    std::transform(ret.memory, ret.memory + ret.size(), ret.memory, ::tolower);
    return ret;
}

String String::toupper() const {
    String ret = *this;
    std::transform(ret.memory, ret.memory + ret.size(), ret.memory, ::toupper);
    return ret;
}

/*
    과제 구현 내용
    아래의 연산자에 대한 코드를 String.cpp 파일에 구현하여라.
    - operator[]
    - operator+
    - operator=
    - operator+=
    - operator==
    - operator!=
    - operator>
    - operator>=
    - operator<
    - operator<=
    - ostream &operator<<
*/

// index 위치의 문자를 리턴하는 연산자 []
const char& String::operator[](unsigned index) const {          // const 리턴
    this->check_index(index);       // out-of-range 검사
    return this->memory[index];
}
char& String::operator[](unsigned index) {                      // non-const 리턴
    this->check_index(index);       // out-of-range 검사
    return this->memory[index];
}

// str1 + str2를 수행하면 두 문자열을 연결한 새로운 String 객체 리턴하는 +
String String::operator+(const String& str) const {             // String + String
    // 새 String 크기 계산
    unsigned newCapacity = this->length() + str.length() + 1;
    String newStr(newCapacity);

    strcpy(newStr.memory, this->memory);    // 기존 문자열 복사
    strcat(newStr.memory, str.memory);      // str 이어 붙이기

    return newStr;
}
String String::operator+(const char* str) const {               // String + char*
    unsigned strLength = strlen(str);
    unsigned newCapacity = this->length() + strLength + 1;
    String newStr(newCapacity);

    strcpy(newStr.memory, this->memory);
    strcat(newStr.memory, str);

    return newStr;
}
String operator+(const char* str1, const String& str2) {        // char* + String
    unsigned str1Length = strlen(str1);
    unsigned newCapacity = str1Length + str2.length() + 1;
    String newStr(newCapacity);

    strcpy(newStr.memory, str1);
    strcat(newStr.memory, str2.memory);

    return newStr;
}

// str1 = str2를 수행하면 str1의 내용이 str2의 내용으로 변경되는 대입연산자 =
String& String::operator=(const String& str) {                  // String = String
    // 동일성 체크
    if (this != &str) 
    {
        this->set(str.memory);
    }
    return *this;
}
String& String::operator=(const char* str) {                    // String = char*
    // 동일성 체크
    if (this->memory != str)
    {
        this->set(str);
    }
    return *this;
}

// str1 += str2를 수행하면 str1의 문자열 뒤에 str2의 문자열이 연결되는 대입연산자 +
String& String::operator+=(const String& str) {                 // String += String
    *this = *this + str;
    return *this;
}
String& String::operator+=(const char* str) {                   // String += char*
    *this = *this + str;
    return *this;
}

// str1 == str2를 수행하면 두 문자열이 
// 일치할 때 true, 아니면 false를 리턴하는 비교연산자 ==
// (대소문자 무시)
bool String::operator==(const String& str) const {              // String == String
    return strcmp(this->memory, str.memory) == 0;
}
bool String::operator==(const char* str) const {                // String == char*
    return strcmp(this->memory, str) == 0;
}
bool operator==(const char* str1, const String& str2) {         // char* == String
    return strcmp(str1, str2.memory) == 0;
}

// str1 != str2를 수행하면 두 문자열이 
// 다를 때 true, 아니면 false를 리턴하는 비교연산자 !=
// (대소문자 무시)
bool String::operator!=(const String& str) const {              // String != String
    return !(*this == str);
}
bool String::operator!=(const char* str) const {                // String != char*
    return !(*this == str);
}
bool operator!=(const char* str1, const String& str2) {         // char* != String
    return !(str1 == str2);
}

// str1 > str2를 수행하면 str1이 사전순으로 str2보다 
// 뒤에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >
// (대소문자 무시)
bool String::operator>(const String& str) const {               // String > String
    return strcmp(this->memory, str.memory) > 0;
}
bool String::operator>(const char* str) const {                 // String > char*
    return strcmp(this->memory, str) > 0;
}
bool operator>(const char* str1, const String& str2) {          // char* > String
    return strcmp(str1, str2.memory) > 0;
}

// str1 >= str2를 수행하면 str1이 사전순으로 str2와
// 같거나 뒤에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >=
// (대소문자 무시)
bool String::operator>=(const String& str) const {              // String >= String
    return strcmp(this->memory, str.memory) >= 0;
}
bool String::operator>=(const char* str) const {                // String >= char*
    return strcmp(this->memory, str) >= 0;
}
bool operator>=(const char* str1, const String& str2) {         // char* >= String
    return strcmp(str1, str2.memory) >= 0;
}

// str1 < str2를 수행하면 str1이 사전순으로 str2보다
// 앞에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 <
// (대소문자 무시)
bool String::operator<(const String& str) const {               // String < String
    return strcmp(this->memory, str.memory) < 0;
}
bool String::operator<(const char* str) const {                 // String < char*
    return strcmp(this->memory, str) < 0;
}
bool operator<(const char* str1, const String& str2) {          // char* < String
    return strcmp(str1, str2.memory) < 0;
}

// str1 <= str2를 수행하면 str1이 사전순으로 str2와
// 같거나 앞에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 <=
// (대소문자 무시)
bool String::operator<=(const String& str) const {              // String <= String
    return strcmp(this->memory, str.memory) <= 0;
}
bool String::operator<=(const char* str) const {                // String <= char*
    return strcmp(this->memory, str) <= 0;
}
bool operator<=(const char* str1, const String& str2) {         // char* <= String
    return strcmp(str1, str2.memory) <= 0;
}

// out << str을 수행 시 ostream 객체로 문자열을 출력하는 연산자 <<
// (프렌드 함수, 대소문자 무시)
std::ostream& operator<<(std::ostream& out, const String& str) {
    out << str.memory;
    return out;
}

void String::check_index(unsigned index) const {
    if (index < this->length()) return;
    throw "out of range";
}

char *String::allocate(unsigned cap) const {
    char *mem = new char[cap];
    if (!mem) throw "fail to allocate mem";
    return mem;
}