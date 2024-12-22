#include"vector_and_stack.h"
#include<map>

using namespace std;

enum types { numbers, operation, open_bracket, close_bracket };

class Term
{
protected:
    types type;
public:
    // Term(types t) :type(t) {};

    virtual types get_type() const noexcept { return type; }
    virtual char get_operation() const noexcept = 0;
    virtual double get_value() const noexcept = 0;
    map<char, int> priorities = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
};

class Number : public Term
{
protected:
    double value;
public:
    virtual char get_operation() const noexcept override { return 'n'; }
    Number(double val) : value(val) { type = numbers; }
    virtual double get_value() const noexcept override { return value; }
};

class Operation : public Term
{
protected:
    char op;
    int priority;
public:
    Operation(char op_) : op(op_), priority(priorities[op]) { type = operation; }
    virtual char get_operation() const noexcept override { return op; };
    virtual double get_value() const noexcept override { return 0; }
    int get_priority() const noexcept
    {
        return priority;
    }
};

class OpenBracket :public Term
{
protected:
    char bracket;
public:
    OpenBracket(char br = '(') : bracket(br) { type = open_bracket; }
    char get_bracket() const noexcept { return bracket; }
    virtual double get_value() const noexcept override { return 0; }
    virtual char get_operation() const noexcept override { return 'o'; }
};

class ClosedBracket : public Term
{
protected:
    char bracket;
public:
    ClosedBracket(char br = ')') : bracket(br) { type = close_bracket; }
    char get_bracket() const noexcept { return bracket; }
    virtual char get_operation() const noexcept override { return 'c'; }
    virtual double get_value() const noexcept override { return 0; }
};
