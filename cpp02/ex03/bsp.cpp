/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:08:47 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/26 15:00:08 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool is_valid_triangle(Point const a, Point const b, Point const c)
{
	if ((a.get_x() == b.get_x() && a.get_y() == b.get_y()) ||
        (a.get_x() == c.get_x() && a.get_y() == c.get_y()) ||
        (b.get_x() == c.get_x() && b.get_y() == c.get_y()))
        return false;
	return true;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (!is_valid_triangle(a, b, c))
		return (0);
	Fixed ProductABP = (b.get_x() - a.get_x()) * (point.get_y() - a.get_y()) - (b.get_y() - a.get_y()) * (point.get_x() - a.get_x());
    Fixed ProductBCP = (c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) - (c.get_y() - b.get_y()) * (point.get_x() - b.get_x());
    Fixed ProductCAP = (a.get_x() - c.get_x()) * (point.get_y() - c.get_y()) - (a.get_y() - c.get_y()) * (point.get_x() - c.get_x());

	if ((ProductABP > 0 && ProductBCP > 0 && ProductCAP > 0) ||
		(ProductABP < 0 && ProductBCP < 0 && ProductCAP < 0))
    		return (1);
	return (0);
}