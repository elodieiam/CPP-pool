#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <exception>
#include <iostream>

class Span
{
	public:
	Span(unsigned int N);
	Span(const Span &src);
	Span& operator = (const Span &src);
	~Span();

	void addNumber(int nb);
	void addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;

	unsigned int getN() const;
	std::vector<int> getSpan() const;
	void	printSpan(void) const;

	class ArrayIsFullException : public std::exception
	{
		public :
		const char* what() const throw();
	};

	class NoDistanceDisplayableException : public std::exception
	{
		public:
		const char* what() const throw();
	};



	private:
	Span();
	unsigned int _N;
	std::vector<int> _span;

};

#endif