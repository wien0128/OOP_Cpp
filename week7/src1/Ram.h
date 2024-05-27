#ifndef RAM_H
#define RAM_H

const int MEM_SIZE = 100 * 1024;

class Ram {
	char mem[MEM_SIZE];
	int size;

public:
	Ram();
	~Ram();
    char read(int addr);
    void write(int addr, char value);

private:
    bool isValidAddr(int addr);
};

#endif