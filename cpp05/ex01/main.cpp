/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:30:39 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/02 14:46:54 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";
	
	std::cout << green << "**************TEST 1**************" << reset << std::endl << std::endl;

	try
	{
		Bureaucrat Elo("elo", 12);
		Bureaucrat Faj(Elo);
		Form	   Attestation("attest", 10, 2);

		std::cout << Elo << std::endl;
		std::cout << Faj << std::endl;
		std::cout << Attestation << std::endl << std::endl;
		Elo.signForm(Attestation);
		std::cout << std::endl << std::endl;
		Faj.signForm(Attestation);
		Elo.increment();
		Elo.increment();
		Elo.signForm(Attestation);
		std::cout << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << std::endl;
	std::cout << green << "**************TEST 2**************" << reset << std::endl << std::endl;
	
	try
	{
		Bureaucrat Elo("Elo", 1);
		Bureaucrat Faj("Faj", 17);
		Faj = Elo;
		std::cout << Elo;
		std::cout << std::endl;
		std::cout << Faj;
		std::cout << std::endl;

		Form Attest("attest", 5, 1);
		std::cout << Attest;
		std::cout << std::endl;
		Elo.signForm(Attest);
		std::cout << Attest;
		std::cout << std::endl;
		Elo.signForm(Attest);
		Faj.signForm(Attest);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl << std::endl;
	std::cout << green << "**************TEST 3**************" << reset << std::endl << std::endl;
	try
	{
		Form Attest("attest", -112, 4500);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}