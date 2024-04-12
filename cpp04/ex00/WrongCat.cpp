/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:56:49 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 15:03:25 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal(), _type("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat (const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->_type = other._type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &other)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
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