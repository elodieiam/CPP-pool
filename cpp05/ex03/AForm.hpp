/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:08:03 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/01 14:51:04 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
	AForm(void);
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm (const AForm &other);
	AForm &operator = (const AForm &other);
	virtual ~AForm(void);

	/*getters*/
	std::string getName(void) const;
	bool		getIsSigned(void) const;
	int		  getGradeToSign(void) const;
	int		  getGradeToExecute(void) const;

	/*member functions*/
	void 			 		  beSigned(const Bureaucrat &bureaucrat);
	void			  execute(Bureaucrat const & executor) const;
	virtual void      perform_exec(void) const = 0;

	/*exceptions*/
	class GradeTooHighException : public std::exception
	{
		public:
		const char* what(void) const throw();	
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

	private:
	const std::string _name;
	bool			  _isSigned;
	const int		  _gradeToSign;
	const int		  _gradeToExecute;

};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif