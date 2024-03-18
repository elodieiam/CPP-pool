/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:32:38 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/08 18:38:34 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int	N = 27;
	
	Zombie	*horde = zombieHorde(N, "JIkaaaaa");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;
	return (0);
}