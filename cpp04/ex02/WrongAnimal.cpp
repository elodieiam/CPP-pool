/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:49:45 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/16 12:12:48 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->_type = other._type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "[WrongAnimal] WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}