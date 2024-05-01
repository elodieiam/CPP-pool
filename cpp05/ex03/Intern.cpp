/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:26:05 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/01 15:01:57 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern (const Intern &other) 
{
	(void) other;
}

Intern& Intern::operator= (const Intern &other) 
{
	(void) other;
	return (*this);
}

Intern::~Intern(void) {}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string form_types[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int			check = -1;
	
	for (int i = 0; i < 3; i++)
	{
		if (form_types[i] == name)
		{
			check = i;
			break ;
		}
	}
	
	switch (check)
	{
		case 0:
			std::cout <<  "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));

		case 1:
			std::cout <<  "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));

		case 2:
			std::cout <<  "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));

		default:
			std::cerr << "Error : form \" " << name << "\"";
			throw Intern::CantCreateFormException();
			return (NULL);
	}
}

const char* Intern::CantCreateFormException::what(void) const throw()
{
	return (" can't be created by the intern ** [Intern] Exception **");
}

