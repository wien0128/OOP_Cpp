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

void String::check_index(unsigned index) const {
    if (index < this->length()) return;
    throw "out of range";
}

char *String::allocate(unsigned cap) const {
    char *mem = new char[cap];
    if (!mem) throw "fail to allocate mem";
    return mem;
}