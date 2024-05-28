#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

if (ac == 2)
{
	try
	{
		BitcoinExchange btc;

		btc.setDataBase();
		btc.processInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}
	else
			std::cout << "Error: could not open file." << std::endl;
}