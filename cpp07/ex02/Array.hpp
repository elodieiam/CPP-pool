/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:40:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/12 17:06:47 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>


template <typename T>
class Array
{
	public:
	Array(void) : _arr(new T[0]), _size(0) {}

	Array(unsigned int n) : _arr(new T[n]), _size(n) 
	{
		for (unsigned int i = 0; i < n; i++)
			this->_arr[i] = 42;
	}
	
	Array(const Array &other) : _size(other._size)
	{
		if (other._arr)
		{
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = other._arr[i];
		}
		else
			this->_arr = NULL;
	}
	
	Array &operator = (const Array &src)
	{
			if (this != &src)
			{
				this->_size = src._size;
				if (this->_arr)
				{
					delete [] this->_arr;
					this->_arr = new T[this->_size];
					for (unsigned int i = 0; i < this->_size; i++)
						this->_arr[i] = src._arr[i];
				}
			}
		return (*this);
	}
	
	~Array(void)
	{
		if (this->_arr)
			delete [] this->_arr;
	}

	/****Member functions****/
	
	T &operator [] (const unsigned int n)
	{
		if (n >= this->_size)
			throw IndexOutOfBoundsException();
		return (this->_arr[n]);
	}

	const T &operator [] (const unsigned int n) const
	{
		if (n >= this->_size)
			throw IndexOutOfBoundsException();
		return (this->_arr[n]);
	}

	unsigned int size(void) const
	{
		return (this->_size);
	}

	/*****EXCEPTION*****/
	class IndexOutOfBoundsException : public std::exception
	{
		public :
		const char* what(void) const throw()
		{
			return ("[Exception] : index is out of bound !");
		}
	};

	private:
	T* 			 _arr;
	unsigned int _size;
};

#endif