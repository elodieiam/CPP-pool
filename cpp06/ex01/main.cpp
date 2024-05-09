/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:37:21 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/09 16:46:16 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";
	
	std::cout << green << "Data before serialization : " << reset << std::endl << std::endl;
	
	Data example;
	Data *data_ptr;
	uintptr_t ptr;

	example.nb = 42;
	example.str = "big boss";

	std::cout << "nb = " << example.nb << std::endl;
	std::cout << "str = " << example.str << std::endl << std::endl;

	std::cout << green << "Data after serialization : " << reset << std::endl << std::endl;

	ptr = Serializer::serialize(&example);
	data_ptr = Serializer::deserialize(ptr);

	std::cout << "nb = " << data_ptr->nb << std::endl;
	std::cout << "str = " << data_ptr->str << std::endl;
}