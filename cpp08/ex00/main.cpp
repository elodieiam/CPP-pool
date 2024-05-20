#include "easyfind.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";

	std::cout << green << "****** Vector ******* : " << reset << std::endl;

	std::vector<int> tab;

	for (int i = 0; i < 15; i++)
		tab.push_back(i);
	try
	{

		std::cout << easyfind(tab, 4) << " was found in the vector !"<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << easyfind(tab, 28) << " was found in the vector !"<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << green << "****** List ******* : " << reset << std::endl;

	std::list<int> tab2;
	for (int i = 0; i < 15; i++)
		tab2.push_front(i);
	try
	{

		std::cout << easyfind(tab2, -43) << " was found in the vector !"<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{

		std::cout << easyfind(tab2, 7) << " was found in the vector !"<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << green << "****** List empty ******* : " << reset << std::endl;
	std::list<int> tab3;
	try
	{

		std::cout << easyfind(tab3, 7) << " was found in the vector !"<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	
}