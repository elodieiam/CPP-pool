/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:08:06 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/30 21:11:00 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("random name"), _isSigned(0), _gradeToSign(10), _gradeToExecute(20) {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

AForm& AForm::operator = (const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
} 

AForm::~AForm(void) {}

/*****getters*****/
std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/****Member functions*****/

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		if (this->_isSigned)
			throw AForm::FormAlreadySignedException();
		else
			this->_isSigned = 1;
	}
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToExecute())
	{
		if (!this->_isSigned)
			throw AForm::FormNotSignedException();
		else
			this->perform_exec();
	}
	else
		throw AForm::GradeTooLowException();
}

/****Exceptions*****/

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("[Form] Exception : Grade Too High!");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("[Form] Exception : Grade Too Low!");
}

const char* AForm::FormAlreadySignedException::what(void) const throw()
{
	return ("[Form] Exception : Form Already Signed!");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("[Form] Exception : Form Not Signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form name = " << form.getName() << std::endl;
	if (form.getIsSigned())
		os << "This form is signed" << std::endl;
	else
		os << "This form is not signed" << std::endl;
	os << "Grade required to sign the form : " << form.getGradeToSign() << std::endl;
	os << "Grade required to execute the form : " << form.getGradeToExecute() << std::endl;

	return (os);
}