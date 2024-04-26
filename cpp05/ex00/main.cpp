/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:51:53 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/26 17:06:11 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";
	
	std::cout << green << "**************TEST 1**************" << reset << std::endl << std::endl;
	try
	{
		Bureaucrat Elo("Elooo", 5);
		std::cout << "Bureaucrat " << Elo.getName() << " created with grade " << Elo.getGrade() << std::endl;
		Elo.increment();
		std::cout << "Grade after incrementation : " << Elo.getGrade() << std::endl;
		Elo.increment();
		std::cout << "Grade after incrementation : " << Elo.getGrade() << std::endl;
		Elo.decrement();
		std::cout << "Grade after decrementation : " << Elo.getGrade() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << green << "**************TEST 2**************" << reset << std::endl << std::endl;
	
	try
	{
		Bureaucrat Charlo("Charlo", -5000);
		std::cout << "Bureaucrat " << Charlo.getName() << " created with grade " << Charlo.getGrade() << std::endl;
		Charlo.increment();
		std::cout << "Grade after incrementation : " << Charlo.getGrade() << std::endl;
		Charlo.increment();
		std::cout << "Grade after incrementation : " << Charlo.getGrade() << std::endl;
		Charlo.decrement();
		std::cout << "Grade after decrementation : " << Charlo.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	std::cout << green << "**************TEST 2**************" << reset << std::endl << std::endl;
	
	try
	{
		Bureaucrat Cami("Cami", 148);
		std::cout << "Bureaucrat " << Cami.getName() << " created with grade " << Cami.getGrade() << std::endl;
		Cami.decrement();
		std::cout << "Grade after decrementation : " << Cami.getGrade() << std::endl;
		Cami.decrement();
		std::cout << "Grade after decrementation : " << Cami.getGrade() << std::endl;
		Cami.decrement();
		std::cout << "Grade after decrementation : " << Cami.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}