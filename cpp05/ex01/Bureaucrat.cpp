/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:46 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/02 13:29:40 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("random name"), _grade(20) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat (const Bureaucrat &other) : _name(other._name)
{
	this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

/******getters******/
const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/****member functions****/
void Bureaucrat::decrement(void)
{
	if ((this->_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::increment(void)
{
	if ((this->_grade -1) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << '\n';
	}
	catch(Form::FormAlreadySignedException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << '\n';
	}
	
}

/****Exceptions*****/
const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("[Bureaucrat] Exception : Grade Too High!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("[Bureaucrat] Exception : Grade Too Low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}