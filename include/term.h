#include"vector_and_stack.h"
#include<map>

using namespace std;

enum types { numbers, operation, open_bracket, close_bracket };
map<char, int> priorities = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

class Term
{
protected:
    types type;
    Term() {};
public:

    types get_type() const noexcept { return type; }
};

class Number : public Term
{
protected:
    double value;
public:
    char get_operation() const noexcept override { return 'n'; }
    Number(double val) : value(val) { type = numbers; }
    double get_value() const noexcept { return value; }
};

class Operation : public Term
{
protected:
    char op;
    int priority;
public:
    Operation(char op_) : op(op_), priority(priorities[op]) { type = operation; }
     char get_operation() const noexcept override { return op; };
     double get_value() const noexcept override { return 0; }
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
     double get_value() const noexcept override { return 0; }
     char get_operation() const noexcept override { return 'o'; }
};

class ClosedBracket : public Term
{
protected:
    char bracket;
public:
    ClosedBracket(char br = ')') : bracket(br) { type = close_bracket; }
    char get_bracket() const noexcept { return bracket; }
     char get_operation() const noexcept override { return 'c'; }
     double get_value() const noexcept override { return 0; }
};
