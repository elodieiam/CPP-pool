/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:33:35 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/26 08:34:24 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point const &point);
		Point &operator=(Point const &nb);
		~Point(void);
		const Fixed getX(void) const;
		const Fixed getY(void) const;
	private:
		const Fixed _x;
		const Fixed _y;
};

#endif