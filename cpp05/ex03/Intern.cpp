/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:26:05 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/01 15:58:56 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) 
{
	this->arr[0] = &Intern::PPF;
	this->arr[1] = &Intern::RRF;
	this->arr[2] = &Intern::SCF;
}

Intern::Intern (const Intern &other) 
{
	 for (int i = 0; i < 3; i++) 
            this->arr[i] = other.arr[i];
}

Intern& Intern::operator= (const Intern &other) 
{
	if (this != &other)
	{
		for (int i = 0; i < 3; i++) 
            this->arr[i] = other.arr[i];
	}
	return (*this);
}

Intern::~Intern(void) {}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string form_types[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	
	for (int i = 0; i < 3; i++)
	{
		if (form_types[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*arr[i])(target));
		}
	}
	std::cerr << "Error : form \" " << name << "\"";
	throw Intern::CantCreateFormException();
	return (NULL);
}

const char* Intern::CantCreateFormException::what(void) const throw()
{
	return (" can't be created by the intern ** [Intern] Exception **");
}

AForm* Intern::PPF(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::RRF(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::SCF(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

