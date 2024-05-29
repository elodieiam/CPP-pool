#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <exception>
#include <cctype>
#include <sstream>

class RPN
{
	private:


	public:
	RPN();
	~RPN();
	RPN(const RPN &src);
	RPN& operator = (const RPN &src);

	void processInput(std::string str);

	void isBaseCorrect(std::string str);

	int isOperator(char c);

	void isSubPartCorrect(std::string str, int i);

	void doOperation(std::string str);

	int check_base(std::string str);

	class ErrorException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

};

#endif