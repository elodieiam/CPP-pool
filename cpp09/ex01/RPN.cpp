#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src) 
{
	if (this != &src)
		*this = src;
}

RPN& RPN::operator = (const RPN &src) 
{
	if (this != &src)
		*this = src;
	return (*this);
}

int RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::isBaseCorrect(std::string str)
{
	if (str.size() < 5)
		throw ErrorException();
	if (!isdigit(str[0]) || !isdigit(str[2]) || !isOperator(str[4])
		|| str[1] != ' ' || str[3] != ' ')
		throw ErrorException();
}

void RPN::isSubPartCorrect(std::string str, int i)
{
	if (!str[i + 3])
		throw ErrorException();
	if (str[i] != ' ' || !isdigit(str[i + 1]) || str[i + 2] != ' ' || !isOperator(str[i + 3]))
		throw ErrorException();
	_stack.push(str[i + 1] - 48);
}

void RPN::processInput(std::string str)
{
	try
	{
		RPN::isBaseCorrect(str);
		_stack.push(str[0] - 48);
		_stack.push(str[2] - 48);
		int i = 5;
		while (str[i])
		{
			RPN::isSubPartCorrect(str, i);
			i += 4;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void RPN::doOperation(std::string str)
{
	long result = _stack.top();
	_stack.pop();

	if (str[4] == '+')
		result += _stack.top();
	else if (str[4] == '-')
		result -= _stack.top();
	else if (str[4] == '*')
		result *= _stack.top();
	else if (str[4] == '/')
	{
		if (_stack.top() == 0)
			throw ErrorException();
		result /= _stack.top();	
	}
	std::cout << "RESULT " << result << std::endl;
	// while(_stack.empty())
	// {

	// }
}



const char *RPN::ErrorException::what(void) const throw()
{
	return ("Error");
}