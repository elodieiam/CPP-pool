/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:20:07 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/19 14:48:44 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {};

Harl::~Harl(void){};

void Harl::complain(std::string level)
{
	void (Harl::*complaints[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int	check = -1;
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			check = i;
			break ;
		}
	}
	switch (check)
	{
		case 0:
			(this->*complaints[0])();
		case 1:
			(this->*complaints[1])();
		case 2:
			(this->*complaints[2])();
		case 3:
			(this->*complaints[3])();
			break;
		default:
		 	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
       		break;
	}
}

void Harl::debug (void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void Harl::info  (void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning (void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years whereas you ";
	std::cout << " started working here since last month." << std::endl;
}

void Harl::error (void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
