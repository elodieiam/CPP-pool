/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:34:00 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 20:25:45 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog (const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "[Dog] WOUAAAAAAAAF" << std::endl;
}

std::string Dog::getType(void) const
{
	return (this->_type);
}

void Dog::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}