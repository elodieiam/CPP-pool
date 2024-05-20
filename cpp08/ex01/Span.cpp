#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src)
{
	_N = src._N;
	_span = src._span;
}

Span& Span::operator = (const Span &src)
{
	if (this != &src)
	{
		_N = src._N;
		_span = src._span;
	}
	return (*this);
}
Span::~Span() {}

void Span::addNumber(int nb)
{
	if (_span.size() >= _N)
		throw Span::ArrayIsFullException();
	_span.push_back(nb);
}

void Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int toFill = _N - _span.size();
	if (toFill <= 0)
		throw Span::ArrayIsFullException();
	int dist = std::distance(begin, end);
	int supr = 0;
	if (dist > toFill)
		supr = dist - toFill;
	_span.insert(_span.end(), begin, end - supr);
}

int Span::shortestSpan() const
{
	if (_span.size() < 2)
		throw Span::NoDistanceDisplayableException();

	std::vector<int> sortedSpan(_span);
	std::sort(sortedSpan.begin(), sortedSpan.end());
	int distance = sortedSpan[1] - sortedSpan[0];
	
	for (unsigned int i = 0; i < (sortedSpan.size() - 1); i++)
	{
		if (sortedSpan[i + 1] - sortedSpan[i] < distance)
			distance = sortedSpan[i + 1] - sortedSpan[i];
	}
	return (distance);
}
int Span::longestSpan() const
{
	if (_span.size() < 2)
		throw Span::NoDistanceDisplayableException();

	std::vector<int> sortedSpan(_span);
	std::sort(sortedSpan.begin(), sortedSpan.end());
	int distance = sortedSpan[_span.size() - 1] - sortedSpan[0];
	return (distance);
}

void	Span::printSpan(void) const
{
	std::vector<int>::const_iterator it1 = _span.begin();
	std::vector<int>::const_iterator it2 = _span.end();
	std::cout << "Span content : " << std::endl;
	
	while(it1 != it2)
	{
		std::cout << *it1 << " " << std::endl;
		it1++;
	}

}
unsigned int Span::getN() const {return _N;}

std::vector<int> Span::getSpan() const {return _span;}

const char* Span::ArrayIsFullException::what() const throw()
{
	return ("The array is full, or of size = 0. It's not possible to add more numbers!");
}

const char* Span::NoDistanceDisplayableException::what() const throw()
{
	return ("No distance displayable : only one number saved or none!");
}

