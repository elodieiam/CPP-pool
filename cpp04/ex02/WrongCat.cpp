/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:56:49 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/16 12:12:58 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Brain.hpp"

WrongCat::WrongCat(void): WrongAnimal(), _type("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_brain = new Brain();

}

WrongCat::WrongCat (const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	delete this->_brain;
}

WrongCat &WrongCat::operator = (const WrongCat &other)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "[WrongCat] MEOOOOOOOOOOOOW" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return (this->_type);
}

