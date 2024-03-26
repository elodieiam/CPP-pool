/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:51:38 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/26 14:03:00 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0){}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {}

Point::~Point(void) {}

Point::Point(Point const &point): _x(point.get_x()), _y(point.get_y()) {}

const Fixed Point::get_x(void) const
{
	return (this->_x);
}

const Fixed Point::get_y(void) const
{
	return (this->_y);
}
