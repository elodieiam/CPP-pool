/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:10:32 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/17 18:11:01 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "[Ice] : default constructor called" << std::endl;
}

Ice::Ice(Ice const &Ice) : AMateria("Ice")
{
	// std::cout << "[Ice] : parametric constructor called" << std::endl;

	this->_type = Ice._type;
}

Ice &Ice::operator=(Ice const &other)
{
	// std::cout << "[Ice] : copy assignment operator called" << std::endl;

	if (this != &other)
		this->_type = other._type;
		
	return (*this);
}

Ice::~Ice(void)
{
	// std::cout << "[Ice] : destructor called" << std::endl;
}

Ice *Ice::clone(void) const
{
	// std::cout << "[Ice] : clone() called" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter& other)
{
	std::cout << "* shoots an ice bolt at " << other.getName() << " *" << std::endl;
}