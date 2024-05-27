#include "Ram.h"
#include <iostream>

using namespace std;


int main()
{
	Ram ram;

	ram.write(100, 'A'); // 100 번지에 'A' 저장
	ram.write(101, 'B'); // 101 번지에 'B' 저장
	ram.write(-2, 'C'); // 메모리 범위가 벚어난 곳에 'C' 저장
	ram.write(102400, 'D'); // 메모리 범위가 벚어난 곳에 'D' 저장
	
	char res = ram.read(100);
	if (res != -1)
		cout << "100 번지의 값 = " << res << endl; // 100 번지 메모리 값 출력
	
	res = ram.read(101);
	if (res != -1)
		cout << "101 번지의 값 = " << res << endl; // 101 번지 메모리 값 출력
	
	res = ram.read(-2);
	if (res != -1)
		cout << "-2 번지의 값 = " << res << endl; // -2 번지 메모리 값 출력
	
	res = ram.read(102400);
	if (res != -1)
		cout << "102400 번지의 값 = " << res << endl; // 102400 번지 메모리 값 출력


	return 0;
}
