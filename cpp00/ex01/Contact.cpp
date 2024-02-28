/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:15:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/28 18:41:08 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Contact::Contact() : index(0) {}

void	Contact::setIndex(int index)
{
	this->index = index;
}

void	Contact::setFirstName(void)
{
	std::string	str("");
	
	while (str.empty())
	{
		std::cout << "Please enter the contact's first name :\n";
		if (!std::getline(std::cin, str))
			std::exit(1);
	}
	this->first_name = str;
}

void	Contact::setLastName(void)
{
	std::string	str("");
	
	while (str.empty())
	{
		std::cout << "Please enter the contact's last name :\n";
		if (!std::getline(std::cin, str))
			std::exit(1);
	}
	this->last_name = str;
}

void	Contact::setNickname(void)
{
	std::string	str("");
	
	while (str.empty())
	{
		std::cout << "Please enter the contact's nickname :\n";
		if (!std::getline(std::cin, str))
			std::exit(1);
	}
	this->nickname = str;
}

void	Contact::setPhoneNumber(void)
{
	std::string	str("");
	
	while (str.empty())
	{
		std::cout << "Please enter the contact's phone number :\n";
		if (!std::getline(std::cin, str))
			std::exit(1);
	}
	this->phone_number = str;
}

void	Contact::setDarkestSecret(void)
{
	std::string	str("");
	
	while (str.empty())
	{
		std::cout << "Please enter the contact's darkest secret :\n";
		if (!std::getline(std::cin, str))
			std::exit(1);
	}
	this->darkest_secret = str;
}

void	Contact::New_contact(int index)
{
	setIndex(index);
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
}

void	Contact::trunc_display(std::string str)
{
	int	i = 0;

	std::cout << "│";
	if (str.size() >= 10)
	{
		while (i <= 8)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << ".";
	}
	else
	{
		for (unsigned int i = 0; i < (10 - str.size()); i++)
			std::cout << " ";
		std::cout << str;
	}
}

void	Contact::display_specific(void)
{
	std::cout << "First name     : " << this->first_name << std::endl;
	std::cout << "Last name      : " << this->last_name << std::endl;
	std::cout << "Nickname       : " << this->nickname << std::endl;
	std::cout << "Phone number   : " << this->phone_number << std::endl;
	std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
}

void	Contact::display_contact(void)
{
	std::string	index("");
	
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│   INDEX  │FIRST NAME│ LAST NAME│ NICKNAME │" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	std::cout << "|         " << this->index;
	trunc_display(this->first_name);
	trunc_display(this->last_name);
	trunc_display(this->nickname);
	std::cout << "│" << std::endl;
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}
