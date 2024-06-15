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
const char& String::operator[](unsigned index) const    // const
{
    this->check_index(index);
    return this->memory[index];
}
char& String::operator[](unsigned index)                // non-const
{
    this->check_index(index);
    return this->memory[index];
}

// str1 + str2를 수행하면 두 문자열을 연결한 새로운 String 객체를 리턴하는 연산자 +
String String::operator+(const String& str) const       // str2가 String 경우
{
    // 새로운 String 객체 생성
    unsigned newCapacity = this->length() + str.length() + 1;
    String newStr(newCapacity);
    
    // str1의 문자열 복사
    unsigned i{ 0 };
    while (this->memory[i] != '\0')
    {
        newStr.memory[i] = this->memory[i];
        ++i;
    }

    // str2의 문자열 이어 붙이기
    unsigned j{ 0 };
    while (str.memory[j] != '\0')
    {
        newStr.memory[i++] = str.memory[j++];
    }
    newStr.memory[i] = '\0';    // 문자열 끝 표시

    return newStr;
}
String String::operator+(const char* str) const         // str2가 const char* 경우
{
    unsigned strLength{ 0 };
    while (str[strLength] != '\0')
    {
        ++strLength;
    }
    
    unsigned newCapacity = this->length() + strLength + 1;
    String newStr(newCapacity);

    unsigned i{ 0 };
    while (this->memory[i] != '\0')
    {
        newStr.memory[i] = this->memory[i];
        ++i;
    }

    unsigned j{ 0 };
    while (str[j] != '\0')
    {
        newStr.memory[i++] = str[j++];
    }
    newStr.memory[i] = '\0';
    
    return newStr;
}
String operator+(const char* str1, const String& str2)  // lvalue가 const char* 경우
{
    unsigned str1Length{ 0 };
    while (str1[str1Length] != '\0')
    {
        ++str1Length;
    }
    
    unsigned newCapacity = str1Length + str2.length() + 1;
    String newStr(newCapacity);

    unsigned i{ 0 };
    while (str1[i] != '\0')
    {
        newStr.memory[i] = str1[i];
        ++i;
    }
    
    unsigned j{ 0 };
    while (str2.memory[j] != '\0')
    {
        newStr.memory[i++] = str2.memory[j++];
    }
    newStr.memory[i] = '\0';
    
    return newStr;
}

// str1 = str2를 수행하면 str1의 내용이 str2의 내용으로 변경하는 대입연산자 =
String& String::operator=(const String& str)            // str2가 String 경우
{
    if (this != &str)
    {
        unsigned newLength = str.length();
        if (newLength + 1 > this->capacity)
        {
            delete[] this->memory;
            this->capacity = newLength + 1;
            this->memory = allocate(this->capacity);
        }
        for (unsigned i = 0; i <= newLength; ++i)
        {
            this->memory[i] = str.memory[i];
        }
    }
    return *this;
}
String& String::operator=(const char* str)              // str2가 const char* 경우
{
    unsigned strLength{ 0 };
    while (str[strLength] != '\0')
    {
        ++strLength;
    }
    
    if (strLength + 1 > this->capacity)
    {
        delete[] this->memory;
        this->capacity = strLength + 1;
        this->memory = allocate(this->capacity);
    }
    
    for (unsigned i = 0; i <= strLength; ++i)
    {
        this->memory[i] = str[i];
    }
    
    return *this;
}

// str1 += str2를 수행하면 str1의 문자열 뒤에 str2의 문자열이 연결되는 대입연산자 +=
String& String::operator+=(const String& str)           // str2가 String 경우
{
    *this = *this + str;
    return *this;
}
String& String::operator+=(const char* str)             // str2가 const char* 경우
{
    *this = *this + str;
    return *this;
}

// str1 == str2를 수행하면 두 문자열이 일치할 때 true, 아니면 false 리턴하는 비교연산자 == (대소문자 무시)
bool String::operator==(const String& str) const        // str2가 String 경우
{
    if (this->length() != str.length())
    {
        return false;
    }

    for (unsigned i = 0; this->memory[i] != '\0'; ++i)
    {
        if (this->tolower().memory[i] != str.tolower().memory[i])
        {
            return false;
        }
    }
    
    return true;
}
bool String::operator==(const char* str) const          // str2가 const char* 경우
{
    String tmp(str);
    unsigned i{ 0 };
    while (this->memory[i] != '\0' && str[i] != '\0')
    {
        if (this->tolower().memory[i] != tmp.tolower().memory[i])
        {
            return false;
        }
        ++i;
    }
    return this->memory[i] == '\0' && str[i] == '\0';
}
bool operator==(const char* str1, const String& str2)   // lvalue가 const char* 경우
{
    return str2 == str1;
}

// str1 != str2를 수행하면 두 문자열이 다를 때 true, 아니면 false를 리턴하는 비교연산자 != (대소문자 무시)
bool String::operator!=(const String& str) const        // str2가 String 경우
{
    return !(*this == str);
}
bool String::operator!=(const char* str) const          // str2가 const char* 경우
{
    return !(*this == str);
}
bool operator!=(const char* str1, const String& str2)   // lvalue가 const char* 경우
{
    return !(str1 == str2);
}

// str1 > str2를 수행하면 str1이 사전순으로 str2보다 뒤에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 > (대소문자 무시)
bool String::operator>(const String& str) const         // str2가 String 경우
{
    unsigned i{ 0 };
    while (this->memory[i] != '\0' && str.memory[i] != '\0')
    {
        if (this->tolower().memory[i] > str.tolower().memory[i])
        {
            return true;
        }
        else if (this->tolower().memory[i] < str.tolower().memory[i])
        {
            return false;
        }
        ++i;
    }
    return this->memory[i] != '\0';
}
bool String::operator>(const char* str) const           // str2가 const char* 경우
{
    String tmp(str);
    unsigned i{ 0 };
    while (this->memory[i] != '\0' && str[i] != '\0')
    {
        if (this->tolower().memory[i] > tmp.tolower().memory[i])
        {
            return true;
        }
        else if (this->tolower().memory[i] < tmp.tolower().memory[i])
        {
            return false;
        }
        ++i;
    }
    return this->memory[i] != '\0';
}
bool operator>(const char* str1, const String& str2)    // lvalue가 const char* 경우
{
    String tmp(str1);
    unsigned i{ 0 };
    while (str1[i] != '\0' && str2.memory[i] != '\0')
    {
        if (tmp.tolower().memory[i] > str2.tolower().memory[i])
        {
            return true;
        }
        else if (tmp.tolower().memory[i] < str2.tolower().memory[i])
        {
            return false;
        }
        ++i;
    }
    return str1[i] != '\0';
}

// str1 >= str2를 수행하면 str1이 사전순으로 str2보다 같거나 뒤에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >= (대소문자 무시)
bool String::operator>=(const String& str) const         // str2가 String 경우
{
    return !(*this < str);
}
bool String::operator>=(const char* str) const           // str2가 const char* 경우
{
    return !(*this < str);
}
bool operator>=(const char* str1, const String& str2)    // lvalue가 const char* 경우
{
    return !(str1 < str2);
}

// str1 > str2를 수행하면 str1이 사전순으로 str2보다 앞에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 > (대소문자 무시)
bool String::operator<(const String& str) const         // str2가 String 경우
{
    unsigned i{ 0 };
    while (this->memory[i] != '\0' && str.memory[i] != '\0')
    {
        if (this->tolower().memory[i] < str.tolower().memory[i])
        {
            return true;
        }
        else if (this->tolower().memory[i] > str.tolower().memory[i])
        {
            return false;
        }
        ++i;
    }
    return str.memory[i] != '\0';
}
bool String::operator<(const char* str) const           // str2가 const char* 경우
{
    String tmp(str);
    unsigned i{ 0 };
    while (this->memory[i] != '\0' && str[i] != '\0')
    {
        if (this->tolower().memory[i] < tmp.tolower().memory[i])
        {
            return true;
        }
        else if (this->tolower().memory[i] > tmp.tolower().memory[i])
        {
            return false;
        }
        ++i;
    }
    return str[i] != '\0';
}
bool operator<(const char* str1, const String& str2)    // lvalue가 const char* 경우
{
    String tmp(str1);
    unsigned i{ 0 };
    while (str1[i] != '\0' && str2.memory[i] != '\0')
    {
        if (tmp.tolower().memory[i] < str2.tolower().memory[i])
        {
            return true;
        }
        else if (tmp.tolower().memory[i] > str2.tolower().memory[i])
        {
            return false;
        }
        ++i;
    }
    return str2.memory[i] != '\0';
}

// str1 >= str2를 수행하면 str1이 사전순으로 str2보다 같거나 앞에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >= (대소문자 무시)
bool String::operator<=(const String& str) const         // str2가 String 경우
{
    return !(*this > str);
}
bool String::operator<=(const char* str) const           // str2가 const char* 경우
{
    return !(*this > str);
}
bool operator<=(const char* str1, const String& str2)    // lvalue가 const char* 경우
{
    return !(str1 > str2);
}

// out << str을 수행시 ostream 객체로 문자열을 출력하는 연산자 << 프렌드 함수 (대소문자 무시)
std::ostream& operator<<(std::ostream& out, const String& str)
{
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