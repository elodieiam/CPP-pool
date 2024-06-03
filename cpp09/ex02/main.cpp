#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PMergeMe Pmerge;

	try
	{
		Pmerge.checkInput(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}