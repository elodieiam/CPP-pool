/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:47:55 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/06 13:01:59 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

PhoneBook::PhoneBook() {};

PhoneBook::~PhoneBook() {};

void	PhoneBook::add_contact(int index)
{
	this->Repertoire[index].New_contact(index);
}

int	check_searched(std::string str)
{
	if (str.size() > 1)
	{
		std::cout << "Error in index format" << std::endl;
		return (1);
	}
	if (str[0] >= '0' && str[0] <= '7')
		return (0);
	std::cout << "Error in index format" << std::endl;
	return (1);
}

void	PhoneBook::display_contact(int	index, int nb_contacts)
{
	std::string	str("");
	
	if (nb_contacts == 0)
	{
		std::cout << "no contact yet ! PhoneBook is empty !" << std::endl;
		return ;
	}
	this->Repertoire[index].display_contact();
	while (str.empty() || check_searched(str))
	{
		std::cout << "Enter the index of the contact to be displayed (0 to 7): " << std::endl << ">";
		if (!getline(std::cin, str))
			return ;
	}
	if (!check_searched(str))
		this->Repertoire[str[0] - 48].display_specific();
}
