/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:42:28 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/17 19:01:12 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& weaponA) : _name(name), _weaponA(weaponA) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weaponA.getType() << std::endl;
}