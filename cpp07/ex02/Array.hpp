/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:40:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/10 19:14:17 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:
	Array(void);

	Array(const unsigned int n) : _arr(new T[size]), _size(size) {}
	
	Array(const Array &other);
	Array &operator = (const Array &other);
	~Array();

	unsigned int size()

	private:
	T* 			 _arr;
	unsigned int _size;
};

#include "Array.tpp"

#endif