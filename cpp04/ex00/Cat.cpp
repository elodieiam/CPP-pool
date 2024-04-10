/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:34:00 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/10 16:12:14 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal(), _type("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat (const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = other._type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "MEOOOOOOOOOOOOW" << std::endl;
}

std::string Cat::getType(void) const
{
	return (this->_type);
}