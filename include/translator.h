#include <string>
#include "term.h"
class ArithmeticExpression
{
protected:
	map<types, size_t> type{ { numbers, 0 }, { operation, 1 }, { open_bracket, 2 }, { close_bracket, 3 } };
	string infix;
	Vector<Term*>polish;
	Vector<Term*>lexems;
public:
	ArithmeticExpression(string infx);
	~ArithmeticExpression();
	string GetInfix() const;
	void Parse();
	void ToPostfix();
	Vector<Term*> GetPostfix() const;
	void PrintPostfix() const;
	double Calculate();
	void Token();
	double GetResult();
};
