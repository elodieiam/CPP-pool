/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:15:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/27 17:52:54 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

void	Contact::setIndex(int index)
{
	this->index = index;
}

void	Contact::setFirstName(void)
{
	std::string	str("");
	
	std::cout << "Please enter the contact's first name :\n";
	if (!std::getline(std::cin, str))
		std::exit(1);
	if (str.empty())
		std::exit(1);
	this->first_name = str;
}

void	Contact::setLastName(void)
{
	std::string	str("");
	
	std::cout << "Please enter the contact's last name :\n";
	if (!std::getline(std::cin, str))
		std::exit(1);
	if (str.empty())
		std::exit(1);
	this->last_name = str;
}

void	Contact::setNickname(void)
{
	std::string	str("");
	
	std::cout << "Please enter the contact's nickname :\n";
	if (!std::getline(std::cin, str))
		std::exit(1);
	if (str.empty())
		std::exit(1);
	this->nickname = str;
}

void	Contact::setPhoneNumber(void)
{
	std::string	str("");
	
	std::cout << "Please enter the contact's phone number :\n";
	if (!std::getline(std::cin, str))
		std::exit(1);
	if (str.empty())
		std::exit(1);
	this->phone_number = str;
}

void	Contact::setDarkestSecret(void)
{
	std::string	str("");
	
	std::cout << "Please enter the contact's darkest secret :\n";
	if (!std::getline(std::cin, str))
		std::exit(1);
	if (str.empty())
		std::exit(1);
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