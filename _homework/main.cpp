#include "String.h"
#include "Vector.h"
#include <iostream>

using std::cout;
using std::endl;

void test_String_class() {
  String s1;
  String s2("12345");
  String s3(s2);

  cout << "s1.empty(): " << (s1.empty() ? "true" : "false") << endl;
  cout << "s1: " << s1.get() << ", s1.length():" << s1.length() << endl;
  cout << "s2: " << s2.get() << ", s2.size(): " << s2.size() << endl;
  cout << "s3: " << s3.get() << ", s3.size(): " << s3.size() << endl;
  cout << endl;

  s3.set("abcd");
  s1.set(s3);
  s1.insert(2, "123");
  s2.insert(3, s3);
  s3.insert(0, "123");

  cout << "s1.empty(): " << (s1.empty() ? "true" : "false") << endl;
  cout << "s1: " << s1.get() << ", s1.length():" << s1.length() << endl;
  cout << "s2: " << s2.get() << ", s2.size(): " << s2.size() << endl;
  cout << "s3: " << s3.get() << ", s3.size(): " << s3.size() << endl;
  cout << endl;

  s1.erase(2, 3);
  s2.erase(3, s3.length());
  s3.erase(0, 3);

  cout << "s1: " << s1.get() << ", s1.length():" << s1.length() << endl;
  cout << "s2: " << s2.get() << ", s2.size(): " << s2.size() << endl;
  cout << "s3: " << s3.get() << ", s3.size(): " << s3.size() << endl;
  cout << endl;

  s1.replace(0, 2, "AB");
  s2.replace(0, 1, s1);
  s3.replace(2, 2, s2);

  cout << "s1: " << s1.get() << ", s1.length():" << s1.length() << endl;
  cout << "s2: " << s2.get() << ", s2.size(): " << s2.size() << endl;
  cout << "s3: " << s3.get() << ", s3.size(): " << s3.size() << endl;
  cout << endl;

  s1.set("aabbccaabbcc");
  unsigned pos = s1.find("bb");
  cout << "s1: " << s1.get() << ", s1.find(\"bb\"): " << pos << endl;
  cout << endl;

  unsigned pos2 = s1.find("bb", pos + 1);
  cout << "s1: " << s1.get() << ", s1.find(\"bb\", pos + 1): " << pos2 << endl;
  cout << endl;

  s2.set("caa");
  pos = s1.find(s2);
  cout << "s1: " << s1.get() << ", s2: " << s2.get() << ", s1.find(s2): " << pos
       << endl;
  cout << endl;

  pos2 = s1.find(s2, pos + 1);
  cout << "s1: " << s1.get() << ", s2: " << s2.get()
       << ", s1.find(s2, pos + 1): "
       << (pos2 == String::npos ? "not found" : "found") << endl;
  cout << endl;
}

template <class T>
void print_Vector(const char *vector_name, const Vector<T> &vector) {
  cout << "---- " << vector_name << " ----" << endl;
  cout << vector_name << ".size(): " << vector.size() << endl;
  cout << vector_name << ".capacity(): " << vector.capacity() << endl;
  for (unsigned i = 0; i < vector.size(); i++)
    cout << vector_name << ".at(" << i << "): " << vector.at(i)
         << (i < vector.size() - 1 ? ", " : "\n");
}

void test_Vector_class() {
  Vector<int> v1;
  Vector<float> v2(3);
  Vector<char> v3(5, 'A');

  print_Vector("v1", v1);
  print_Vector("v2", v2);
  print_Vector("v3", v3);
  cout << endl;

  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(1.0);
  v2.push_back(2.0);
  v2.push_back(3.0);
  v3.set(1, 'B');
  v3.set(2, 'C');
  v3.set(3, 'D');
  v3.set(4, 'E');
  v3.set(100, 'Z');

  print_Vector("v1", v1);
  print_Vector("v2", v2);
  print_Vector("v3", v3);
  cout << endl;

  
  v1.insert(1, 100);
  v2.erase(1);
  v2.erase(1000);
  v3.pop_back();

  print_Vector("v1", v1);
  print_Vector("v2", v2);
  print_Vector("v3", v3);
  cout << endl;
}

int main() {
  cout << ":::: Test String Class ::::" << endl;
  test_String_class();

  cout << ":::: Test Vector Class ::::" << endl;
  test_Vector_class();
}