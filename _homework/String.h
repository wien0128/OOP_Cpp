#ifndef __STRING_H__
#define __STRING_H__

class String {
  char *memory;       // 동적으로 할당한 메모리 주소를 가리키는 포인터
  unsigned capacity;  // 동적으로 할당한 메모리의 크기

public:
  // find 멤버 함수에서 결과를 찾지 못할 때 반환하는 값(unsigned int 중 가장 큰 값)
  // 초기화는 String.cpp 파일에서 할 것
  static const unsigned npos;

  // 생성자
  String();  // 메모리의 크기(capacity)가 10인 동적 메모리를 할당하고, 이 메모리에 빈 문자열을 저장
  String(const char *str);    // str 문자열을 저장할 메모리 공간을 동적으로 생성하고, 이 문자열을 memory에 저장
  String(const String &str);  // 복사 생성자: str에 저장된 문자열을 memory에 저장

  // 소멸자
  ~String();  // memory가 가리키는 동적 메모리를 해제


  // memory의 문자열을 str로 변경
  void set(const char *str);    
  void set(const String &str);

  // 문자열을 리턴하는 (인라인) 함수
  const char *get() const { return memory; };
  
  // index 위치의 문자를 반환
  char at(unsigned index) const { return memory[index]; };
  
  // 빈문자열이면 true, 아니면 false를 리턴
  bool empty() const { return length() == 0; };

  // length(), size() 모두 문자열의 길이를 반환
  unsigned length() const;
  unsigned size() const;


  // 위치(인덱스)가 position인 위치부터 길이가 length인 부분 문자열을 String 객체로 리턴
  String substr(unsigned position, unsigned length) const;
  
  // memory의 position 위치에 str 을 삽입
  void insert(unsigned position, const char *str);
  void insert(unsigned position, const String &str);
  
  // memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 삭제
  void erase(unsigned position, unsigned length);
  
  // memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 str로 치환
  void replace(unsigned position, unsigned length, const char *str);
  void replace(unsigned position, unsigned length, const String &str);

  
  // memory에 저장된 문자열의 position 위치부터 str 문자열을 찾으며,
  // position 뒤의 위치에서 가장 처음 str이 나타나는 위치의 인덱스를 반환
  // 찾지 못할 경우 npos를 리턴
  unsigned find(const char *str, unsigned position = 0) const;    
  unsigned find(const String &str, unsigned position = 0) const;
};

#endif