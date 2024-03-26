/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:36:27 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/26 15:03:35 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	bool is_inside;
	{
		std::cout << "test 1 : " << std::endl;
	Point a(1, 1);
	Point b(5, 1);
	Point c(3, 5);
	
	Point p1(3, 4);
	is_inside = bsp(a, b, c, p1);
	if (is_inside)
		std::cout << "the point is inside the triangle" << std::endl;
	else
		std::cout << "the point is outside the triangle" << std::endl;
	Point p2(16, 18);
	is_inside = bsp(a, b, c, p2);
	if (is_inside)
		std::cout << "the point is inside the triangle" << std::endl;
	else
		std::cout << "the point is outside the triangle" << std::endl;
	Point p3(2, 1);
	is_inside = bsp(a, b, c, p3);
	if (is_inside)
		std::cout << "the point is inside the triangle" << std::endl;
	else
		std::cout << "the point is outside the triangle" << std::endl;
	}
	{
		std::cout << "test 2 : invalid triangle " << std::endl;

		Point a(1, 1);
		Point b(1, 1);
		Point c(3, 5);
		Point p1(3, 4);
		is_inside = bsp(a, b, c, p1);
		if (is_inside)
			std::cout << "the point is inside the triangle" << std::endl;
		else
			std::cout << "the point is outside the triangle" << std::endl;
	}
	{
		std::cout << "test 3 : " << std::endl;

		Point a(-5, 1.2);
		Point b(-2, -5);
		Point c(-8, -5);
		Point p1(-12, -16);
		is_inside = bsp(a, b, c, p1);
		if (is_inside)
			std::cout << "the point is inside the triangle" << std::endl;
		else
			std::cout << "the point is outside the triangle" << std::endl;
		Point p2(-3, -4.01);
		is_inside = bsp(a, b, c, p2);
		if (is_inside)
			std::cout << "the point is inside the triangle" << std::endl;
		else
			std::cout << "the point is outside the triangle" << std::endl;
	}
	
}