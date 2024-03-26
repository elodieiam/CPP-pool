/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:21:29 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/26 12:51:37 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void): _fixedValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int fixed_point)
{
	long result = 0;
	
	// std::cout << "Int constructor called" << std::endl;
	const int scale_factor = 1 << _fractBits;
	result = roundf(fixed_point * scale_factor);
	if (result > 2147483647)
		this->_fixedValue = 2147483647;
	else if (result < -2147483648)
		this->_fixedValue = -2147483648;
	this->_fixedValue = result;
}

Fixed::Fixed(const float fixed_point)
{
	long result = 0;
	
	// std::cout << "Float constructor called" << std::endl;
	const int scale_factor = 1 << _fractBits;
	result = static_cast<int>(roundf(fixed_point * scale_factor));
	if (result > 2147483647)
		this->_fixedValue = 2147483647;
	else if (result < -2147483648)
		this->_fixedValue = -2147483648;
	this->_fixedValue = result;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}



Fixed::Fixed (const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator = (const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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
	// std::cout << "getRawBits member function called" << std::endl;
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


bool	Fixed::operator<(const Fixed &a) const
{
	return (this->getRawBits() < a.getRawBits());
}

bool	Fixed::operator>(const Fixed &a) const
{
	return (this->getRawBits() > a.getRawBits());
}

bool	Fixed::operator>=(const Fixed &a) const
{
	return (this->getRawBits() >= a.getRawBits());
}

bool	Fixed::operator<=(const Fixed &a) const
{
	return (this->getRawBits() <= a.getRawBits());
}

bool	Fixed::operator==(const Fixed &a) const
{
	return (this->getRawBits() == a.getRawBits());
}

bool	Fixed::operator!=(const Fixed &a) const
{
	return (this->getRawBits() != a.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &a) const
{
	return (this->toFloat() + a.toFloat());
}

Fixed	Fixed::operator-(const Fixed &a) const
{
	return (this->toFloat() - a.toFloat());
	
}

Fixed	Fixed::operator*(const Fixed &a) const
{
	return (this->toFloat() * a.toFloat());
}

Fixed	Fixed::operator/(const Fixed &a) const
{
	return (this->toFloat() / a.toFloat());
}

Fixed &Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed const &Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}
Fixed &Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}
Fixed const &Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed &Fixed::operator++(void)
{
	this->_fixedValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedValue++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_fixedValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedValue--;
	return (tmp);
}