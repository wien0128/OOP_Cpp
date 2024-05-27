#include "Ram.h"
#include <iostream>
#include <cstring>

using namespace std;

Ram::Ram() : mem(), size(MEM_SIZE)
{
    memset(mem, '0', MEM_SIZE);
}

Ram::~Ram()
{
    cout << "메모리에서 제거됨";
}

char Ram::read(int addr)
{
    if (isValidAddr(addr))
    {
        return mem[addr];
    }
    else
    {
        cout << "주소 범위를 벗어남.\n";
        return -1;
    }
}

void Ram::write(int addr, char value)
{
    if (isValidAddr(addr))
    {
        mem[addr] = value;
    }
    else
    {
        cout << "주소 범위를 벗어남.\n";
    }
}

bool Ram::isValidAddr(int addr)
{
    return !(addr >= size || addr < 0);
}