// 여기에 정의되지 않은 String 클래스의 멤버 함수들을 구현

#include "String.h"
#include <cstring>		// strcpy, strlen, strstr
#include <algorithm>	// copy, copy_backward

const unsigned String::npos = -1; // 부호 없는 정수기에 -1이면 최대값으로 반영

// 기본 생성자
String::String() : memory(new char[11]), capacity(10)
{
    // 빈 문자열에 끝을 표시
	memory[0] = '\0';
}

// C 스타일 문자열을 인자로 받는 생성자
String::String(const char* str) : capacity(std::strlen(str)), memory(new char[capacity + 1])
{
	std::strcpy(memory, str);
}

// 복사 생성자
String::String(const String& str) : capacity(str.capacity), memory(new char[capacity + 1])
{
	std::strcpy(memory, str.memory);
}

// 소멸자
String::~String()
{
	delete[] memory;
}

// 문자열 설정 
void String::set(const char* str)
{
	size_t len = std::strlen(str);
	// str의 길이가 capacity보다 긴가?
	if (len > capacity)
	{
		// 기존 메모리 해제 후 capacity+1 만큼 늘려서 재할당
		delete[] memory;
		capacity = len;
		memory = new char[capacity + 1];
	}
	std::strcpy(memory, str);
}

// String 객체 문자열 설정
void String::set(const String& str)
{
	// 자기 자신에 대한 대입 방지
	if (this != &str)
	{
		set(str.memory);
	}
}

// 문자열 길이 반환
unsigned String::length() const
{
	return std::strlen(memory);
}

unsigned String::size() const
{
	return length();
}

// 부분 문자열 반환
String String::substr(unsigned position, unsigned len) const
{
	// position이 문자열의 끝을 가리키면 빈 문자열 반환
	if (position > length()) return String();

    // min(요청된 부분 문자열의 길이, 실제로 추출 가능한 길이)
    // 가능한 최대 길이를 넘지 않는 문자열을 추출하기 위해 min 사용
	unsigned n = std::min(len, length() - position);
	char* temp = new char[n + 1];   // '\0' 공간을 위한 +1
	std::copy(memory + position, memory + position + n, temp);
	temp[n] = '\0';     // 문자열의 끝 표시

	String result(temp);    // String <- char* 형 변환
	delete[] temp;
	return result;
}

// 문자열 삽입
void String::insert(unsigned position, const char* str)
{
    // NullPointerException 처리
	if (str == nullptr) return;

    // 길이가 0인 문자열은 삽입 불가
	auto strLen = std::strlen(str);
	if (strLen == 0) return;

    // IndexOutOfBoundsException 처리
    // 문자열의 끝에 str 삽입
	auto oldLen = this->length();
	if (position > oldLen) position = oldLen;

	unsigned newCapacity = oldLen + strLen; // 필요한 새로운 메모리 크기 계산

	// 할당해야 할 newCapacity가 기존 capacity 보다 큰가?
	if (newCapacity > capacity)
	{
        // '\0'을 위한 +1
		char* newMemory = new char[newCapacity + 1];

        // newMemory{ 문자열시작~position + str + position~문자열끝}
		std::copy(memory, memory + position, newMemory);
		std::copy(str, str + strLen, newMemory + position);
		std::copy(memory + position, memory + oldLen, newMemory + position + strLen);

		// 문자열 끝 표시
		newMemory[newCapacity] = '\0';

		// 기존 메모리 해제 후 멤버 변수 재할당
		delete[] memory;
		memory = newMemory;
		capacity = newCapacity;
	}
	else 
	{
		// 기존 메모리로 충분히 삽입 가능하다.
		// 따라서 더 효율적인 메모리 관리를 위해 새로운 메모리 할당을 피함
		std::copy_backward(memory + position, memory + oldLen, memory + oldLen + strLen);
		std::copy(str, str + strLen, memory + position);
		// 문자열 끝 표시
		memory[oldLen + strLen] = '\0';
	}
}

// String 객체 문자열 삽입
void String::insert(unsigned position, const String& str)
{
	insert(position, str.get());
}

// 문자열 삭제
void String::erase(unsigned position, unsigned len)
{
	// IndexOutOfBoundsException 처리
	if (position > length()) return; 

	// min(요청된 삭제 문자열의 길이, 실제로 삭제 가능한 길이)
    // 가능한 최대 길이를 넘지 않는 문자열을 삭제하기 위해 min 사용
	unsigned n = std::min(len, length() - position);
	std::copy(memory + position + n, memory + length(), memory + position);
	// 문자열 끝 표시
	memory[length() - n] = '\0';
}

// 문자열 치환
void String::replace(unsigned position, unsigned len, const char* str)
{
	erase(position, len);
	insert(position, str);
}

// String 객체 문자열 치환
void String::replace(unsigned position, unsigned len, const String& str)
{
	replace(position, len, str.memory);
}

// position에서 부터 가장 처음 만나는 str의 위치 반환
// 찾지 못할 경우 npos 반환
unsigned String::find(const char* str, unsigned position) const
{
	// memory+position에서 부터 str을 찾지 못할 경우 nullptr 반환
	const char* found = strstr(memory + position, str);

	// str을 찾았는가?
	if (found == nullptr)
	{
		return npos;
	}
	else
	{
		// 포인터 간 차이(ptrdiff_t)를 unsigned로 형 변환
		return static_cast<unsigned>(found - memory);
	}
}

// String 객체에서 문자열 찾기
unsigned String::find(const String& str, unsigned position) const
{
	return find(str.memory, position);
}