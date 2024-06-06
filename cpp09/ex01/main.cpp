#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : the program takes one string as a parameter" << std::endl;
		return (1);
	}
	try 
	{
		RPN rpn;
		rpn.doOperation(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}