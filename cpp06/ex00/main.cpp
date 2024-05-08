#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string nb = av[1];
		ScalarConverter::convert(nb);
	}
}