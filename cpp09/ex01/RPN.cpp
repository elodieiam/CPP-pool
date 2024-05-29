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

int RPN::check_base(std::string str)
{
	int nb_operands = 0;
	int nb_operators = 0;
	char c;

	std::istringstream stream(str);
	while (stream.get(c))
	{
		if (isdigit(c))
			nb_operands++;
		else if (isOperator(c))
			nb_operators++;
	}
	if (nb_operators != (nb_operands - 1))
		return (0);
	return (1);


}

void RPN::doOperation(std::string str)
{
	std::stack<int> stack;
	std::istringstream stream(str);
	char c;
	long top1;
	long top2;

	if (!check_base(str))
		throw RPN::ErrorException();
	while (stream.get(c))
	{
		if (c == ' ')
			continue ;
		if (stream.peek() == ' ' || stream.peek() == -1)
		{
			if (isdigit(c))
				stack.push(c - 48);
			else
			{
				if (stack.size() < 2)
					throw RPN::ErrorException();
				else
				{
					top1 = stack.top();
					stack.pop();
					top2 = stack.top();
					stack.pop();
					if (c == '+' && (top1 + top2 <= 2147483647) && (top1 + top2 >= -2147483648))
						stack.push(top2 + top1);
					else if (c == '-' && (top1 - top2 <= 2147483647) && (top1 - top2 >= -2147483648))
						stack.push(top2 - top1);
					else if (c == '*' && (top1 * top2 <= 2147483647) && (top1 * top2 >= -2147483648))
						stack.push(top2 * top1);
					else if (c == '/' && top1 != 0 && (top1 / top2 <= 2147483647) && (top1 / top2 >= -2147483648))
						stack.push(top2 / top1);
					else
						throw RPN::ErrorException();
				}
			}
		}
		else
			throw RPN::ErrorException();
	}
	if (stack.empty())
		throw RPN::ErrorException();
	std::cout << stack.top() << std::endl;
}



const char *RPN::ErrorException::what(void) const throw()
{
	return ("Error");
}