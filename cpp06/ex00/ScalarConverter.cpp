/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:43 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/08 15:42:45 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(std::string str)
{
	if (str.empty())
		return (print_error("[error] : empty string"));
	if (is_specific(str))
		display_specific(str);
	else if (is_char(str))
		display_char(str);
	else if (is_int(str))
		display_int(str);
	else if (is_float(str))
		display_float(str);
	else if (is_double(str))
		display_double(str);
	else
		display_error();
		
}

void print_error(std::string str)
{
	std::string red =  "\033[1;31m";
	std::string reset = "\033[0m";

	std::cerr << red << str << reset << std::endl;
}