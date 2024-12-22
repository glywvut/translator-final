#include "translator.h"

ArithmeticExpression::ArithmeticExpression(string infx) { this->infix = infx; }

ArithmeticExpression::~ArithmeticExpression()
{
	for (size_t i = 0; i < lexems.size(); i++)
	{
		delete lexems[i];
	}
}

void ArithmeticExpression::Parse() {
	string str = infix;
	size_t size = lexems.size();
	map<types, size_t> states{ {numbers, 0}, {operation, 1}, {open_bracket, 2}, {close_bracket, 3} };
	size_t state{};
	Stack<char> stack;
	if (size == 0) throw logic_error("there`s no expression");
	state = states[lexems[0]->get_type()];
	if (state == 1)
		throw logic_error("operation can't be the first symbol!");
	else if (state == 2)
		stack.push('(');
	else if (state == 3)
		throw logic_error("')' can't be the first symbol!");
	for (size_t i = 1; i < size; i++)
	{
		if (lexems[i]->get_type() == open_bracket) stack.push('(');
		else if (lexems[i]->get_type() == close_bracket) {
			if (!stack.IsEmpty()) stack.pop();
			else throw logic_error("incorrect brackets!");
		}
		switch (state)
		{
		case 0:
			if (lexems[i]->get_type() == open_bracket || lexems[i]->get_type() == numbers)
				throw logic_error("incorrect syntax!");
			state = states[lexems[i]->get_type()];
			break;
		case 1:
			if (lexems[i]->get_type() == operation || lexems[i]->get_type() == close_bracket)
				throw logic_error("incorrect syntax!");
			state = states[lexems[i]->get_type()];
			break;
		case 2:
			if (lexems[i]->get_type() == close_bracket || lexems[i]->get_type() == operation)
				throw logic_error("incorrect syntax!");
			state = states[lexems[i]->get_type()];
			break;
		case 3:
			if (lexems[i]->get_type() == numbers || lexems[i]->get_type() == open_bracket)
				throw logic_error("incorrect syntax!");
			state = states[lexems[i]->get_type()];
			break;
		default:
			throw logic_error("incorrect syntax!");
			break;
		}
	}
	state = states[lexems[size - 1]->get_type()];
	if (state == 1 || state == 2)
		throw logic_error("incorrect syntax!");
	if (!stack.IsEmpty())
		throw logic_error("incorrect brackets!");
}

void ArithmeticExpression::ToPostfix() {
	Stack<Term*> stack;
	size_t size = lexems.size();
	for (size_t i = 0; i < size; ++i) {
		if (lexems[i]->get_type() == numbers) polish.push_back(lexems[i]);
		else if (lexems[i]->get_type() == operation) {
			if (stack.IsEmpty()) {
				stack.push(lexems[i]);
			}
			else {
				while (!stack.IsEmpty() && stack.top()->get_type() == operation && \
					static_cast <Operation*>(lexems[i])->get_priority() <= static_cast<Operation*>(stack.top())->get_priority()) {
					polish.push_back(stack.top());
					stack.pop();
				}
				stack.push(lexems[i]);
			}
		}
		else if (lexems[i]->get_type() == open_bracket) {
			stack.push(lexems[i]);
		}
		else if (lexems[i]->get_type() == close_bracket) {
			while ((stack.top()->get_type() != open_bracket) && !stack.IsEmpty()) {
				polish.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
	}
	while (!stack.IsEmpty())
	{
		polish.push_back(stack.top());
		stack.pop();
	}
}

void ArithmeticExpression::Token()
{
	string str;
	bool is_numb = false;
	char c{};
	for (size_t i = 0; i < infix.size(); i++)
	{
		c = infix[i];
		if (!is_numb)
		{
			if (c == '(')
				lexems.push_back(new OpenBracket);
			else if (c == '*' || c == '/' || c == '+' || c == '-')
				lexems.push_back(new Operation(c));
			else if (c == ')')
				lexems.push_back(new ClosedBracket);
			else if (c >= '0' && c <= '9' || c == '.')
			{
				is_numb = true;
				str += c;
			}
			else throw logic_error("incorrect syntax!");
		}
		else
		{
			if (c >= '0' && c <= '9' || c == '.') {
				str += c;
			}
			else if (c == '(')
			{
				is_numb = false;
				lexems.push_back(new Number(stod(str)));
				lexems.push_back(new OpenBracket);
				str.clear();
			}
			else if (c == '*' || c == '/' || c == '+' || c == '-')
			{
				is_numb = false;
				lexems.push_back(new Number(stod(str)));
				lexems.push_back(new Operation(c));
				str.clear();
			}
			else if (c == ')')
			{
				is_numb = false;
				lexems.push_back(new Number(stod(str)));
				lexems.push_back(new ClosedBracket);
				str.clear();
			}
			else throw logic_error("incorrect syntax!");
		}
	}
	if (!str.empty()) lexems.push_back(new Number(stod(str)));
}

double ArithmeticExpression::Calculate()
{
	Stack<double> stack;
	double right_numb, left_numb;
	types t = {};
	for (size_t i = 0; i < polish.size(); ++i)
	{
		t = polish[i]->get_type();
		if (t == numbers)
		{
			stack.push(static_cast<Number*>(polish[i])->get_value());
		}
		else
		{
			right_numb = stack.top();
			stack.pop();
			left_numb = stack.top();
			stack.pop();
			switch (static_cast<Operation*>(polish[i])->get_operation())
			{
			case '*':
				stack.push(left_numb * right_numb);
				break;
			case '/':
				if (right_numb == 0)
					throw ("division by zero");
				stack.push(left_numb / right_numb);
				break;
			case '+':
				stack.push(left_numb + right_numb);
				break;
			case '-':
				stack.push(left_numb - right_numb);
				break;
			}
		}
	}
	return stack.top();
}

string ArithmeticExpression::GetInfix() const
{
	return infix;
}

Vector<Term*> ArithmeticExpression::GetPostfix() const
{
	return polish;
}

void  ArithmeticExpression::PrintPostfix() const
{
	cout << "Постфиксная форма: ";
	for (size_t i = 0; i < polish.size(); ++i)
	{
		if (polish[i]->get_type() == numbers)
		{
			cout << static_cast<Number*>(polish[i])->get_value();
		}
		else
		{
			cout << static_cast<Operation*>(polish[i])->get_operation();
		}
		if (i == polish.size() - 1) cout << "\n";
	}
}

double ArithmeticExpression::GetResult()
{
	Token();
	Parse();
	ToPostfix();
	PrintPostfix();
	cout << "Вычисленный результат: ";
	return Calculate();
}
