/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:37:32 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/19 14:40:14 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;
	
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments.\n" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}