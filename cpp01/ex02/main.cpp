/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:38:40 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/17 16:51:30 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string 	str("HI THIS IS BRAIN");
	std::string		*stringPTR = &str;
	std::string		&stringREF = str;

	std::cout << "Memory address of str : " << &str << std::endl;
	std::cout << "Memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF : " << &stringREF << std::endl << std::endl;
	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;
}