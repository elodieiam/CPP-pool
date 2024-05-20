#include "MutantStack.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";

	MutantStack<int> stack;
	std::cout << green << "****** Tests on regular functions ******* : " << reset << std::endl;
	if (stack.empty())
		std::cout << "my stack is empty !" << std::endl;

	stack.push(17);
	stack.push(23);
	stack.push(89);
	stack.push(77);

	MutantStack<int>::iterator it1 = stack.begin();
	MutantStack<int>::iterator it2 = stack.end();

	std::cout << green << "****** Iterate in regular order ******* : " << reset << std::endl;

	while (it1 != it2)
	{
		std::cout << *it1 << std::endl;
		it1++;
	}

	std::cout << std::endl << std::endl;
	std::cout << green << "****** Iterate in regular order ******* : " << reset << std::endl;

	MutantStack<int>::reverse_iterator rit1 = stack.rbegin();
	MutantStack<int>::reverse_iterator rit2 = stack.rend();

	while (rit1 != rit2)
	{
		std::cout << *rit1 << std::endl;
		rit1++;
	}
	std::cout << std::endl << std::endl;

	std::cout << green << "****** Comparison test with a list ******* : " << reset << std::endl;
	std::list<int>		list;
	list.push_back(17);
	list.push_back(23);
	list.push_back(89);
	list.push_back(77);


	std::list<int>::iterator itb = list.begin();
	std::list<int>::iterator ite = list.end();
	while (itb != ite)
	{
		std::cout << *itb << std::endl;
		itb++;
	}

	std::list<int>::reverse_iterator ritb = list.rbegin();
	std::list<int>::reverse_iterator rite = list.rend();
	while (ritb != rite)
	{
		std::cout << *ritb << std::endl;
		ritb++;
	}


}