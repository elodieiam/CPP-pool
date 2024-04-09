/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:16:30 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/09 15:36:05 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal parametric constructor called" << std::endl;
}
Animal::Animal (const Animal &other)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	
	this->_type = other._type;
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

void Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}