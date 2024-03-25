/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:21:29 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/25 18:26:10 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void): _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int fixed_point)
{
	std::cout << "Int constructor called" << std::endl;
	const int scale_factor = 1 << _fractBits;
	this->_fixedValue = roundf(fixed_point * scale_factor);
}

Fixed::Fixed(const float fixed_point)
{
	std::cout << "Float constructor called" << std::endl;
	const int scale_factor = 1 << _fractBits;
	this->_fixedValue = static_cast<int>(roundf(fixed_point * scale_factor));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}



Fixed::Fixed (const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits(int const raw)
{
	 this->_fixedValue = raw;
}

float Fixed::toFloat( void ) const
{
	const int scale_factor = 1 << _fractBits;
	return (static_cast<float>(_fixedValue) / scale_factor);
}

int Fixed::toInt( void ) const
{
	const int scale_factor = 1 << _fractBits;
	return (_fixedValue / scale_factor);
}
