#ifndef ACC_H
#define ACC_H


class Accumulator {
    int value;
public:
    Accumulator(int value);
    Accumulator& add(int n);
    int get() const;
};

#endif