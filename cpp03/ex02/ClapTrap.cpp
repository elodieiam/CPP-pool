/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:07:33 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/03 15:48:10 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void): _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}


ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Parametric constructor called" << std::endl;
}


ClapTrap::ClapTrap (const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->_hitPoints || !this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << " , causing " << this->_attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 4294967295)
		return ;
	if (!this->_hitPoints || !this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "Claptrap " << this->_name << " sustained " << amount << " points of damage. ";
	std::cout << this->_hitPoints << " hit points remaining" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount > 4294967295)
		return ;
	if (!this->_hitPoints || !this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
	this->_hitPoints += amount;
	std::cout << "Claptrap " << this->_name << " was repaired by " << amount << " points. ";
	std::cout << this->_hitPoints << " hit points remaining" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void ClapTrap::changeAttackDamage(int newAttackDamage)
{
	if (newAttackDamage >= 0 && newAttackDamage <= 2147483647)
		this->_attackDamage = newAttackDamage;
}


