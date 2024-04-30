/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:11:16 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/30 21:28:20 by elrichar         ###   ########.fr       */
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
		f1.execute(Elo);
		f1.execute(Elo);
		f1.execute(Faj);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}