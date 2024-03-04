/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:26:10 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/04 11:39:33 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string	str("");
	
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; av[i]; i++)
	{
		str = av[i];
		for (int j = 0; av[i][j]; j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;
		if (av[i])
			std::cout << " ";
	}
	return (std::cout << std::endl, 0);
}