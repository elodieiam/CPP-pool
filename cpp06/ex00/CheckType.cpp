/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:12:48 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/07 15:56:25 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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
