/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:25:47 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/01 15:42:24 by elrichar         ###   ########.fr       */
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
	
	private:
	AForm* PPF(std::string target);
	AForm* RRF(std::string target);
	AForm* SCF(std::string target);
	AForm* (Intern::*arr[3])(std::string target);
};

#endif