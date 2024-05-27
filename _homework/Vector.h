#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>    // copy, copy_backward, fill

template <class T>
class Vector {
    T* _memory;   // 동적으로 생성한 T 타입의 배열을 가리킬 포인터
    unsigned _capacity; // 동적으로 할당된 메모리의 크기
    unsigned _size;   // 배열에 저장된 요소의 수

    // 배열 용량 확장 함수 (2배)
    void _expand_capacity() 
    {
        // capacity 용량 설정
        _capacity = (_capacity > 0) ? _capacity * 2 : 1;

        // 확장된 메모리 생성
        T* new_memory = new T[_capacity];
        
        // 기존 메모리 값 복사 후 해제, 새 메모리 할당
        std::copy(_memory, _memory + _size, new_memory);
        delete[] _memory;
        _memory = new_memory;
    }

public:
    // 생성자 리스트 이용하여 멤버 변수 초기화
    Vector(unsigned capacity = 5) : _capacity(capacity), _size(0), _memory(new T[capacity]) {
        // _memory의 크기를 매개변수 capacity 크기로 동적으로 할당하고
        // 동적으로 할당된 배열의 요소는 없도록 초기화하는 생성자를 여기에 구현
    }
    
    // 생성자 리스트 이용하여 멤버 변수 초기화와 동적 메모리 element로 초기화
    Vector(unsigned size, const T& element) : _capacity(size * 2), _size(size), _memory(new T[_capacity]) {
        // 메모리의 크기와 요소의 개수를 size 만큼 설정
        // size의 두 배 크기의 메모리를 동적으로 생성
        // 동적 메모리의 각 요소의 값은 element로 초기화

        // element로 메모리 초기화
        std::fill(_memory, _memory + _size, element);
    }

    // 소멸자
    ~Vector() {
        // 동적 메모리 해제
        delete[] _memory;
    }

    unsigned size() const {
        // 동적 배열에 저장된 요소의 갯수를 리턴
        return _size;
    }

    unsigned capacity() const {
        // 동적 배열의 가용 가능한 최대 크기를 리턴
        return _capacity;
    }

    const T& at(unsigned index) const {
        // 동적 배열의 index 위치에 저장된 요소를 리턴
        // 배열의 크기를 넘는 인덱스틑 고려하지 않아도 됨
        return _memory[index];
    }

    void set(unsigned index, const T& element) {
        // index가 유효할 경우만 동적 배열의 index 위치의 요소를 element로 변경
        // index 요소가 유효하다는 의미는 배열의 요소의 갯수를 넘지 않는 범위의 인덱스라는 의미

        // IndexOutOfBoundsException 예외 처리
        if (index >= _size) return;
        
        _memory[index] = element;
    }

    bool empty() const {
        // 배열에 저장된 요소가 없을 경우 true, 그렇지 않다면 false를 리턴
        return size() == 0;
    }

    void push_back(const T& element) {
        // 배열의 끝에 element를 추가

        // 원소의 개수가 가용량을 넘어서면 메모리 확장 후 삽입
        if (_size >= _capacity)
        {
            _expand_capacity();
        }
        _memory[_size++] = element;
    }

    void pop_back() {
        // 배열의 마지막 요소를 제거
        // 더이상 제거할 요소가 없다면 무시
        if (_size > 0)
        {
            _size--;
        }
    }

    void erase(unsigned index) {
        // index가 유효한 경우, 배열의 index 위치의 요소를 삭제
        // 유효하지 않은 경우는 아무 일도 일어나지 않음
        
        // IndexOutOfBoundsException 예외 처리
        if (index >= _size) return;

        // index + 1의 위치 부터 끝까지를 index 부터 덮어 씌움
        // index 부터 한 칸씩 땡기는 효과
        std::copy(_memory + index + 1, _memory + _size, _memory + index);
        _size--;
    }

    void insert(unsigned index, const T& element) {
        // index 위치가 유효한 경우(배열의 요소의 수를 넘지 않는 위치)
        // index 위치에 element를 삽입
        
        // IndexOutOfBoundsException 예외 처리
        if (index >= _size) return;

        // 원소의 개수가 가용량을 넘어서면 메모리 확장
        if (_size >= _capacity)
        {
            _expand_capacity();
        }

        // 벡터의 끝에 추가하는 경우 복사 없이 직접 대입
        if (index == _size)
        {
            _memory[_size] = element;
        }
        else
        {
            // 그외에 경우 index 부터 끝까지의 요소를 한 칸씩 뒤로 미룬 후 삽입
            std::copy_backward(_memory + index, _memory + _size, _memory + _size + 1);
            _memory[index] = element;
        }
        _size++;
    }
};

#endif