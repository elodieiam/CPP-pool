/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:43 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/07 16:06:49 by elrichar         ###   ########.fr       */
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
	if (is_specific(str))
		display_specific(str);
	else if (is_char(str))
		display_char(str);
	else if (is_int(str))
		display_int(str);
	else
		display_error();
		
}