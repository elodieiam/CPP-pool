/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:11:16 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/01 15:25:08 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";
	
	std::cout << green << "**************TEST 1**************" << reset << std::endl << std::endl;
	std::cout << green << "Presidential form" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("Elo", 4);
		Bureaucrat Faj("Faj", 16);
		PresidentialPardonForm f1("form 1");

		std::cout << Elo << std::endl;
		std::cout << Faj << std::endl;
		std::cout << f1 << std::endl;

		Elo.signForm(f1);
		Elo.executeForm(f1);
		f1.execute(Elo);
		f1.execute(Elo);
		Faj.executeForm(f1);
		f1.execute(Faj);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << green << "**************TEST 2**************" << reset << std::endl << std::endl;
	std::cout << green << "Robotomy form" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("Elo", 10);
		RobotomyRequestForm f2("form 2");

		std::cout << Elo << std::endl;
		std::cout << f2 << std::endl;
		Elo.signForm(f2);
		f2.execute(Elo);
		f2.execute(Elo);
		f2.execute(Elo);

		Bureaucrat Faj("Faj", 99);
		f2.execute(Faj);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << green << "**************TEST 3**************" << reset << std::endl << std::endl;
	std::cout << green << "Shruberry form" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("Elo", 142);
		Bureaucrat Faj("Faj", 6);
		ShrubberyCreationForm f3("form 3");

		Elo.signForm(f3);
		f3.execute(Faj);
		f3.execute(Faj);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}