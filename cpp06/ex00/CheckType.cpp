/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:12:48 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/09 18:32:43 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


#include "ScalarConverter.hpp"

bool is_specific(std::string str)
{
	if (str == "+inff" || str == "-inff" || str == "nanf" 
		|| str == "+inf" || str == "-inf" || str == "nan")
		return (true);
	return (false);
}

bool is_char(std::string str)
{
	if (str.size() == 1)
	{
		if (str[0] >= '0' && str[0] <= '9')
			return (false);
		return (true);
	}
	return (false);
}

bool is_int(std::string str)
{
	int i = 0;
	long value = 0;
	std::istringstream stream(str);
	
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (!(stream >> value))
	{
		print_error("[error] : istringstream failed");
		return (false);
	}
	if ((value < std::numeric_limits<int>::min()) || value > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

bool is_float(std::string str)
{
	int i = 0;
	double value = 0;
	std::istringstream stream(str);
	
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (!str[i])
		return (false);
	i++;
	if (!str[i])
		return (false);
	while (str[i] && str[i] != 'f')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (!str[i])
		return (false);
	if (str[i + 1])
		return (false);

	if (str[0] == '-' || str[0] == '+')
	{
		std::string substr = str.substr(1);
		std::istringstream stream(substr);
		if (!(stream >> value))
		{
			print_error("[error] : istringstream failed");
			return (false);
		}
	}
	else
	{
		if (!(stream >> value))
	{
		print_error("[error] : istringstream failed");
		return (false);
	}
	}
	if ((value < std::numeric_limits<float>::min()) || value > std::numeric_limits<float>::max())
		return (false);
	return (true);
}

bool is_double(std::string str)
{
	int i = 0;
	long double value = 0;
	std::istringstream stream(str);
	
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (!str[i])
		return (false);
	i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	
	if (str[0] == '-' || str[0] == '+')
	{
		std::string substr = str.substr(1);
		std::istringstream stream(substr);
		if (!(stream >> value))
		{
			print_error("[error] : istringstream failed");
			return (false);
		}
	}
	else
	{
		if (!(stream >> value))
	{
		print_error("[error] : istringstream failed");
		return (false);
	}
	}
	if ((value < std::numeric_limits<double>::min()) || value > std::numeric_limits<double>::max())
		return (false);
	return (true);
}