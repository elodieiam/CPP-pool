/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:34:00 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/10 16:11:46 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal(), _type("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog (const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = other._type;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "WOUAAAAAAAAF" << std::endl;
}

std::string Dog::getType(void) const
{
	return (this->_type);
}