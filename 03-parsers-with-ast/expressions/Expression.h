#pragma once
class Driver;

class Expression {
public:
    virtual int eval(const Driver& driver) const = 0;
};