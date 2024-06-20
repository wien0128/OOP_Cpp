#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <ostream>

template<class T>
class Vector {
    T *_memory;
    unsigned _capacity;
    unsigned _size;

public:
    Vector(unsigned capacity = 5);
    Vector(unsigned size, const T &element);
    Vector(const T arr[], unsigned size);
    Vector(const Vector<T> &vector);
    ~Vector();

    unsigned size() const { return this->_size; }
    unsigned capacity() const { return this->_capacity; }
    const T &at(unsigned index) const { return _memory[index]; }
    void set(unsigned index, const T &element);
    bool empty() const { return _size == 0; }
    void push_back(const T &element);
    void pop_back();
    void erase(unsigned index);
    void insert(unsigned index, const T &element);

    /*
        과제 구현 내용
        아래의 멤버 함수 및 연산자에 대한 코드를 구현하여라.
        - begin()
        - end()
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
    // Vector의 첫번째 요소에 대한 포인터 반환
    T *begin() { return _memory; }                                      // non-const 리턴
    const T *begin() const { return _memory; }                          // const 리턴

    // Vector의 마지막 다음 요소에 대한 포인터 반환
    T *end() { return _memory + _size; }                                // non-const 리턴
    const T *end() const { return _memory + _size; }                    // const 리턴

    // Vector의 index 위치의 값을 반환하는 연산자를 정의할 것
    T &operator[](unsigned index) { return _memory[index]; }            // non-const 리턴
    const T &operator[](unsigned index) const { return _memory[index]; }// const 리턴

    // vector1 = vector2 수행 시 vector1의 내용을 vector2로 변경하는 =
    Vector<T> &operator=(const Vector<T> &vector) {
        if (this != &vector)
        {
            delete[] _memory;
            _size = vector._size;
            _capacity = vector._capacity;
            _memory = new T[_capacity];

            for (unsigned i = 0; i < _size; ++i)
            {
                _memory[i] = vector._memory[i];
            }
        }
        return *this;
    }

    // vector1 + vector2 수행시 두 벡터가 연결된 새로운 벡터를 리턴하는 연산자 +
    Vector<T> operator+(const Vector<T> &vector) const {
        Vector<T> res(_size + vector._size);
        for (unsigned i = 0; i < _size; ++i)
        {
            res._memory[i] = _memory[i];
        }
        for (unsigned i = 0; i < vector._size; ++i)
        {
            res._memory[_size + i] = vector._memory[i];
        }
        res._size = _size + vector._size;

        return res;
    }

    // vector1 += vector2 수행 시 vector1 뒤에 vector2 연결되는 연산자 +=
    Vector<T> &operator+=(const Vector<T> &vector) {
        unsigned new_size = _size + vector._size;
        if (new_size > _capacity)
        {
            reallocate(new_size);
        }
        for (unsigned i = 0; i < vector._size; ++i)
        {
            _memory[_size + i] = vector._memory[i];
        }
        _size = new_size;

        return *this;
    }

    // vector1 == vector2 수행 시 vector1과 vector2의 모든 값이 
    // 같은지 아닌지를 판별하는 연산자 ==
    bool operator==(const Vector<T> &vector) const {
        if (_size != vector._size)
        {
            return false;
        }
        for (unsigned i = 0; i < _size; ++i)
        {
            if (_memory[i] != vector._memory[i])
            {
                return false;
            }
        }
        return true;
    }

    // vector1 != vector2 수행 시 vector1과 vector2의 값들 중 하나라도 다르면
    // true, 그렇지 않으면 false를 리턴하는 연산자 !=
    bool operator!=(const Vector<T> &vector) const {
        return !(*this == vector);
    }
/*
    // vector1 > vector2
    bool operator>(const Vector<T>& vector) const {
        for (unsigned i = 0; i < _size && i < vector._size; ++i)
        {
            if (_memory[i] > vector._memory[i]) return true;
            if (_memory[i] < vector._memory[i]) return false;
        }
        return _size > vector._size;
    }

    // vector1 >= vector
    bool operator>=(const Vector<T>& vector) const {
        return *this > vector || *this == vector;
    }

    // vector1 < vector2
    bool operator<(const Vector<T>& vector) const {
        return !(*this >= vector);
    }

    // vector1 <= vector2
    bool operator<=(const Vector<T>& vector) const {
        return !(*this > vector);
    }
*/
    // 출력 스트림으로 vector를 출력하는 프렌드 함수를 정의할 것
    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &vector) {
        // 템플릿 클래스의 경우는 프렌드 함수를 여기에 정의해야 함
        // 만약 벡터에 <1, 2, 3, 4, 5>가 저장되어 있을 경우. 출력 형식은 [ 1, 2, 3, 4, 5 ]
        out << "[ ";
        for (unsigned i = 0; i < vector._size; ++i)
        {
            out << vector._memory[i];
            if (i < vector._size - 1)
                out << ", ";
            else
                out << "";
        }
        out << " ]";
        return out;
    }

private:
    // utility member functions
    // 여기부터는 이미 구현되어 있으므로 구현이 필요 없음
    void check_index(unsigned index) const;
    T *allocate(unsigned capacity) const;
    void reallocate() { reallocate(_size); }
    void reallocate(unsigned size);
};

template<class T>
Vector<T>::Vector(unsigned capacity)
        : _memory(nullptr), _capacity(capacity), _size(0) {
    this->_memory = this->allocate(this->_capacity);
}

template<class T>
Vector<T>::Vector(unsigned size, const T &element)
        : _memory(nullptr), _capacity(size * 2), _size(size) {
    this->_memory = this->allocate(this->_capacity);
    for (unsigned i = 0; i < this->_size; i++)
        this->_memory[i] = element;
}

template<class T>
Vector<T>::Vector(const T arr[], unsigned size): _memory(nullptr), _capacity(size * 2), _size(size) {
    this->_memory = this->allocate(this->_capacity);
    for (unsigned i = 0; i < this->_size; i++) this->_memory[i] = arr[i];
}

template<class T>
Vector<T>::Vector(const Vector<T> &vector)
        : _memory(nullptr), _capacity(vector._capacity), _size(vector._size) {
    this->_memory = this->allocate(this->_capacity);
    for (unsigned i = 0; i < vector._size; i++)
        this->_memory[i] = vector._memory[i];
}

template<class T>
Vector<T>::~Vector() {
    delete[] this->_memory;
}

template<class T>
void Vector<T>::set(unsigned index, const T &element) {
    this->check_index(index);
    this->_memory[index] = element;
}

template<class T>
void Vector<T>::push_back(const T &element) {
    reallocate(this->_size + 1);
    _memory[_size++] = element;
}

template<class T>
void Vector<T>::pop_back() {
    if (this->_size == 0)
        throw "vector is empty";
    this->_size--;
}

template<class T>
void Vector<T>::erase(unsigned index) {
    check_index(index);
    for (unsigned i = index; i < this->_size - 1; i++)
        this->_memory[i] = this->_memory[i + 1];
    this->_size--;
}

template<class T>
void Vector<T>::insert(unsigned index, const T &element) {
    this->reallocate(this->_size + 1);
    for (unsigned i = index; i < this->_size; i++)
        this->_memory[i + 1] = this->_memory[i];
    this->_memory[index] = element;
    this->_size++;
}

template<class T>
void Vector<T>::check_index(unsigned index) const {
    if (index < this->_size)
        return;
    throw "out of index";
}

template<class T>
T *Vector<T>::allocate(unsigned capacity) const {
    T *memory = new T[capacity];
    if (!memory)
        throw "fail to allocate memory";
    return memory;
}

template<class T>
void Vector<T>::reallocate(unsigned size) {
    if (size < this->_capacity)
        return;
    unsigned capacity = size * 2;
    T *memory = this->allocate(capacity);
    for (unsigned i = 0; i < this->_size; i++)
        memory[i] = this->_memory[i];
    delete[] this->_memory;
    this->_memory = memory;
    this->_capacity = capacity;
}

#endif // __VECTOR_H__