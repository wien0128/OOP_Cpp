#ifndef __STRING_H__
#define __STRING_H__

#include <ostream>

class String {
    char *memory; // 동적으로 할당한 메모리 주소를 가리키는 포인터
    unsigned capacity; // 동적으로 할당한 메모리의 크기

public:
    static const unsigned npos;

    String(unsigned capacity = 10);

    String(const char *str);

    String(const String &str);

    ~String();

    void set(const char *str);

    void set(const String &str);

    const char *get() const { return memory; };

    char at(unsigned index) const { return memory[index]; };

    bool empty() const { return length() == 0; };

    unsigned length() const;

    unsigned size() const;

    String substr(unsigned start, unsigned length) const;

    void insert(unsigned index, const char *str);

    void insert(unsigned index, const String &str);

    void erase(unsigned start, unsigned length);

    void replace(unsigned start, unsigned length, const char *str);

    void replace(unsigned start, unsigned length, const String &str);

    unsigned find(const char *str, unsigned pos = 0) const;

    unsigned find(const String &str, unsigned pos = 0) const;

    String tolower() const;   // 원래의 문자열을 소문자로 바꾼 새로운 문자열 반환
    String toupper() const;   // 원래의 문자열을 대문자로 바꾼 새로운 문자열 반환

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
    // index 위치의 문자를 리턴하는 연산자 []를 정의할 것
    const char &operator[](unsigned index) const;   // const 버전
    char &operator[](unsigned index);               // 비 const 버전

    // str1 + str2를 수행하면 두 문자열을 연결한 새로운 String 객체를 리턴하는 연산자 +를 정의할 것
    String operator+(const String &str) const;      // str2가 String인 경우
    String operator+(const char *str) const;        // str2가 const char *인 경우
    friend String operator+(const char *str1, const String &str2);

    // str1 = str2을 수행하면 str1의 내용이 str2의 내용으로 변경하는 대입연산자 =를 정의할 것
    String &operator=(const String &str);           // str2가 String인 경우
    String &operator=(const char *str);             // str2가 const char *인 경우

    // str1 += str2를 수행하면 str1의 문자열 뒤에 str2의 문자열이 연결되는 대입연산자 +=를 정의할 것
    String &operator+=(const String &str);          // str2가 String인 경우
    String &operator+=(const char *str);            // str2가 const char *인 경우

    // str1 == str2를 수행하면 두 문자열이 일치할 때 true, 아니면 false를 리턴하는 비교연산자 ==를 정의할 것(대소문자 무시)
    bool operator==(const String &str) const;       // str2가 String인 경우
    bool operator==(const char *str) const;         // str2가 const char *인 경우
    friend bool operator==(const char *str1, const String &str2);

    // str1 != str2를 수행하면 두 문자열이 다를 때 true, 아니라면 false를 리턴하는 비교연산자 !=를 정의할 것(대소문자 무시)
    bool operator!=(const String &str) const;       // str2가 String인 경우
    bool operator!=(const char *str) const;         // str2가 const char *인 경우
    friend bool operator!=(const char *str1, const String &str2);

    // str1 > str2를 수행하면 str1이 사전순으로 str2보다 뒤에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >를 정의할 것(대소문자 무시)
    bool operator>(const String &str) const;        // str2가 String인 경우
    bool operator>(const char *str) const;          // str2가 const char *인 경우
    friend bool operator>(const char *str1, const String &str2);

    // str1 >= str2를 수행하면 str1이 사전순으로 str2와 같거나 뒤에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >=를 정의할 것(대소문자 무시)
    bool operator>=(const String &str) const;       // str2가 String인 경우
    bool operator>=(const char *str) const;         // str2가 const char *인 경우
    friend bool operator>=(const char *str1, const String &str2);

    // str1 > str2를 수행하면 str1이 사전순으로 str2보다 앞에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >를 정의할 것(대소문자 무시)
    bool operator<(const String &str) const;        // str2가 String인 경우
    bool operator<(const char *str) const;          // str2가 const char *인 경우
    friend bool operator<(const char *str1, const String &str2);

    // str1 >= str2를 수행하면 str1이 사전순으로 str2와 같거나 앞에 나오는 경우 true, 아니면 false를 리턴하는 비교연산자 >=를 정의할 것(대소문자 무시)
    bool operator<=(const String &str) const;       // str2가 String인 경우
    bool operator<=(const char *str) const;         // str2가 const char *인 경우
    friend bool operator<=(const char *str1, const String &str2);

    // out << str을 수행시 ostream 객체로 문자열을 출력하는 연산자 <<를 프렌드 함수로 정의할 것(대소문자 무시)
    friend std::ostream &operator<<(std::ostream &out, const String &str);

private:
    // utility member functions
    // 여기부터는 이미 구현되어 있으므로 구현이 필요 없음
    void check_index(unsigned index) const;
    char *allocate(unsigned cap) const;
};

#endif // __STRING_H__