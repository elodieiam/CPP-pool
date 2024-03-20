/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:47:32 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/20 18:09:22 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
	Fixed(void);
	Fixed (const Fixed &other);
	Fixed &operator = (const Fixed &other);
	~Fixed(void);
	int	getRawBits(void) const;
	void setRawBits(int const raw);

	private:
	int	_fixedValue;
	static const int _fractBits = 8;	
};

#endif