/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:12:18 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/10 16:11:09 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parametric constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

}

ScavTrap::ScavTrap (const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->_hitPoints || !this->_energyPoints)
	{
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << " , causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;	
}

