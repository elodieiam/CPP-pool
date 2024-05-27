#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;

if (ac == 2)
{

	try
	{

		btc.setDataBase();
		btc.processInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
}