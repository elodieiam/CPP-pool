/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:31:37 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/10 17:46:18 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <typename Type>
void swap(Type &a, Type &b)
{
	Type tmp = a;

	a = b;
	b = tmp;
}

template <typename Type>
Type min(const Type &a, const Type &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename Type>
Type max(const Type &a, const Type &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif