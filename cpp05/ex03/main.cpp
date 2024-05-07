/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:11:16 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/03 14:08:11 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";
	
	std::cout << green << "**************TEST 1**************" << reset << std::endl << std::endl;
	std::cout << green << "Presidential form" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("Elo", 4);
		Intern	   Charlo;
		AForm *f1;

		std::cout << Elo << std::endl;

		f1 = Charlo.makeForm("PresidentialPardonForm", "form 1");
		std::cout << *f1 << std::endl;

		Elo.signForm(*f1);
		Elo.executeForm(*f1);

		delete f1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << green << "**************TEST 2**************" << reset << std::endl << std::endl;
	std::cout << green << "Robotomy form" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("Elo", 4);
		Intern	   Charlo;
		AForm *f2;
		
		std::cout << Elo << std::endl;
		f2 = Charlo.makeForm("RobotomyRequestForm", "form 2");
		std::cout << *f2 << std::endl;
		
		Elo.signForm(*f2);
		Elo.executeForm(*f2);
		Elo.executeForm(*f2);

		Bureaucrat Faj("Faj", 99);
		Elo.executeForm(*f2);


		delete f2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << green << "**************TEST 3**************" << reset << std::endl << std::endl;
	std::cout << green << "Shruberry form" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("Elo", 4);
		Intern	   Charlo;
		AForm *f3;

		std::cout << Elo << std::endl;
		f3 = Charlo.makeForm("ShrubberyCreationForm", "form 3");
		std::cout << *f3 << std::endl;
		
		Elo.signForm(*f3);
		Elo.executeForm(*f3);

		delete f3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << green << "**************TEST 4**************" << reset << std::endl << std::endl;
	std::cout << green << "Wrong form" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("Elo", 4);
		Intern	   Charlo;
		AForm *f4;

		std::cout << Elo << std::endl;
		f4 = Charlo.makeForm("Wrong file name", "form 4");
		std::cout << *f4 << std::endl;
		
		Elo.signForm(*f4);
		Elo.executeForm(*f4);

		delete f4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}