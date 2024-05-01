/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:25:47 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/01 14:46:37 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
	Intern(void);
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern(void);

	AForm* makeForm(std::string name, std::string target);

	class CantCreateFormException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};
	
};

#endif