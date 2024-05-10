/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:57 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/10 15:11:58 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


void display_specific(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "+inf" || str == "-inf")
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;	

	}
	else
	{
		std::cout << "float: " << str << std::endl;
		if (str == "nanf")
			std::cout << "double: " << "nan" << std::endl;
		else if (str == "+inff")
			std::cout << "double: " << "+inf" << std::endl;
		else
			std::cout << "double: " << "-inf" << std::endl;		
	}
}

void display_char(std::string str)
{
	std::cout << "char: " << "'" << str << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void display_int(std::string str)
{
	std::istringstream stream(str);
	int nb = 0;

	stream >> nb;
	if (nb < 32 || nb == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "'" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}
void display_float(std::string str)
{
	std::istringstream stream(str);
	float nb = 0;

	stream >> nb;
	if (nb < 32 || nb == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "'" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (nb < static_cast<float>(std::numeric_limits<int>::min()) || nb > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	if (nb == static_cast<int>(nb))
	{
		std::cout << "float: " << nb << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;

	}
	else
	{
		std::cout << "float: " << nb << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nb) << std::endl;

	}
}

void display_double(std::string str)
{
	std::istringstream stream(str);
	double nb = 0;

	stream >> nb;
	if (nb < 32 || nb == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "'" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if ((nb < static_cast<double>(std::numeric_limits<int>::min())) || (nb > static_cast<double>(std::numeric_limits<int>::max())))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	if (static_cast<float>(nb) == static_cast<int>(nb))
		std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
	if (nb == static_cast<int>(nb))
		std::cout << "double: " << nb << ".0" << std::endl;
	else
		std::cout << "double: " << nb  << std::endl;
}

void display_error(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;	
}



