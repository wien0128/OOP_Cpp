#include "Accumulator.h"

Accumulator::Accumulator(int value)
{
    this->value = value;
}

Accumulator& Accumulator::add(int n)
{
    this->value += n;
    return *this;
}

int Accumulator::get() const
{
    return value;
}