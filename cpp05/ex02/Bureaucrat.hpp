/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:08:23 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/01 15:23:59 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat (const Bureaucrat &other);
	Bureaucrat &operator = (const Bureaucrat &other);
	~Bureaucrat(void);

	/*getters*/
	const std::string getName(void) const;
	int				  getGrade(void) const;

	/*member functions*/
	void			  decrement(void);
	void			  increment(void);
	void			  signForm(AForm &form);
	void			  executeForm(AForm const & form);
	
	/*Exceptions*/
	class GradeTooHighException : public std::exception
	{
		public :
		const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
		const char* what(void) const throw();
	};

	private:
	const std::string _name;
	int				  _grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif