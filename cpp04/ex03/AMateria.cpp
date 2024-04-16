/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:30:08 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/16 17:50:50 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) 
{
	std::cout << "[AMateria] : default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "[AMateria] : parametric constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
	std::cout << "[AMateria] : copy constructor called" << std::endl;
	this->_type = other._type;
}

AMateria &AMateria::operator = (AMateria const &other)
{
	std::cout << "[AMateria] : copy assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria(void) 
{
	std::cout << "[AMateria] : destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

