/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:57 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/07 16:07:25 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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

void display_int(std::string str);


void display_error(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;	
}
