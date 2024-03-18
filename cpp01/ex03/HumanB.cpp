/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:38:12 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/18 11:12:25 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) 
{
	this->_weaponB = NULL;
}

HumanB::~HumanB() {}

void	HumanB::attack(void) const 
{
	if (this->_weaponB == NULL)
		std::cout << _name << " cannot attack because has no weapon !" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weaponB = &weapon;
}