/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:34:00 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 20:25:31 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat (const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "[cat] MEOOOOOOOOOOOOW" << std::endl;
}

std::string Cat::getType(void) const
{
	return (this->_type);
}

void Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}