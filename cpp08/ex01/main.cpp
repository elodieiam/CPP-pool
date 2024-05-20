#include "Span.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";

	std::cout << green << "****** Fill with add number ******* : " << reset << std::endl;

	Span span(10);
	try
	{
		span.addNumber(12);
		span.addNumber(2);
		span.addNumber(4);
		span.addNumber(6);
		span.addNumber(28);
		span.addNumber(14);
		span.addNumber(-1);
		span.addNumber(-18);
		span.addNumber(18956);
		span.addNumber(-632);
		span.addNumber(11);
		span.addNumber(112);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	span.printSpan();
	std::cout << std::endl << std::endl;

	std::cout << green << "****** Shortest and longest distance ******* : " << reset << std::endl;
	std::cout << "shortest distance = " << span.shortestSpan() << std::endl;
	std::cout << "longest distance = " << span.longestSpan() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << green << "****** Add a range of numbers ******* : " << reset << std::endl;

	std::vector<int> filler(10000);
	for (unsigned int i = 0; i < filler.size(); i++) 
		filler[i] = i;
	
	Span span2(10005);
	try
	{
	span2.addNumber(13);
	span2.addNumber(12);
	span2.addNumber(11);
	span2.addNumberRange(filler.begin(), filler.end());
	span2.addNumber(15);
	span2.addNumberRange(filler.begin(), filler.end());
	span2.addNumberRange(filler.begin(), filler.end());


	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

try
{
	std::cout << "shortest distance = " << span2.shortestSpan() << std::endl;
	std::cout << "longest distance = " << span2.longestSpan() << std::endl;
}

catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	std::cout << green << "****** Empty vector ******* : " << reset << std::endl;
	Span empty(0);

	try
	{
		empty.addNumber(2);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		empty.shortestSpan();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		empty.longestSpan();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	//span2.printSpan();

	





}