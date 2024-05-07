#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	(void) ac;
	std::string nb = av[1];
	ScalarConverter::convert(nb);
}