/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:14:36 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/07 18:28:10 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*new_zombie;
	new_zombie = new Zombie(name);
	if (!new_zombie)
		return (NULL);
	return (new_zombie);
}