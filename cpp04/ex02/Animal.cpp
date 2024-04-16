/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:16:30 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/16 12:17:37 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal (const Animal &other)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = other._type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator = (const Animal &other)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::setIdea(int index, std::string idea)
{
	(void)index;
	(void)idea;
	std::cout << "[Animal] : error : animals don't have brains !" << std::endl;
}

std::string Animal::getIdea(int index) const
{
	(void) index;
	std::cout << "[Animal] : error : animals don't have brains !" << std::endl;
	return "";
}
