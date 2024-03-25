/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:25:58 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/25 18:45:31 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed(void);
	Fixed(const int fixed_point);
	Fixed(const float fixed_point);
	Fixed (const Fixed &other);
	~Fixed(void);
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed &operator = (const Fixed &other);
	
	

	bool			operator<(const Fixed &a, const Fixed &b);
	bool			operator>(const Fixed &a, const Fixed &b);
	bool			operator>=(const Fixed &a, const Fixed &b);
	bool			operator<=(const Fixed &a, const Fixed &b);
	bool			operator==(const Fixed &a, const Fixed &b);
	bool			operator!=(const Fixed &a, const Fixed &b);

	Fixed			operator+(const Fixed &a, const Fixed &b);
	Fixed			operator-(const Fixed &a, const Fixed &b);
	Fixed			operator*(const Fixed &a, const Fixed &b);
	Fixed			operator/(const Fixed &a, const Fixed &b);

	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
	
	private:
	int	_fixedValue;
	static const int _fractBits = 8;	
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);



#endif