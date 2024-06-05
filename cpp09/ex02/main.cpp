#include "PmergeMe.hpp"

//penser à vérifier les doublons !

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