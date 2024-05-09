/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:45:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/09 16:45:49 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct s_data
{
	int nb;
	std::string str;
}  Data;

class Serializer
{
	public:
	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);

	private:
	Serializer(void);
	Serializer(const Serializer &other);
	Serializer& operator=(const Serializer &other);
	~Serializer(void);
};

#endif