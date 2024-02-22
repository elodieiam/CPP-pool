/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:29:23 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/22 16:19:53 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	int 	i(1);
	int		j(0);
	char	c('1');
	
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			c = std::toupper(av[i][j]);
			std::cout << c;
			j++;
		}
		std::cout << " ";
		i++;
	}
	std::cout << "\n";
	return (0);
}