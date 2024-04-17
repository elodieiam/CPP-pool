/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:10:32 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/17 15:57:36 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "[Cure] : default constructor called" << std::endl;
}

Cure::Cure(Cure const &cure) : AMateria("cure")
{
	// std::cout << "[Cure] : parametric constructor called" << std::endl;

	this->_type = cure._type;
}

Cure &Cure::operator=(Cure const &other)
{
	// std::cout << "[Cure] : copy assignment operator called" << std::endl;

	if (this != &other)
		this->_type = other._type;
		
	return (*this);
}

Cure::~Cure(void)
{
	// std::cout << "[Cure] : destructor called" << std::endl;
}

Cure *Cure::clone(void) const
{
	// std::cout << "[Cure] : clone() called" << std::endl;

	return (new Cure(*this));
}

void Cure::use(ICharacter& other)
{
	std::cout << "* heals " << other.getName() << "'s wounds *" << std::endl;
}