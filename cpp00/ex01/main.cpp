/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:00:16 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/27 17:58:55 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	cmd_line("");
	int			i;

	i = 0;
	std::cout << "PhoneBook : ADD to create a new contact\n";
	std::cout << "          : SEARCH to find a contact\n";
	std::cout << "          : EXIT to exit PhoneBook\n";
	while (1)
	{
		std::cout << ">";
		if (!getline(std::cin, cmd_line))
			return (1);
		if (!cmd_line.compare("EXIT"))
			break ;
		else if (!cmd_line.compare("SEARCH"))
		{
			
		}
		else if (!cmd_line.compare("ADD"))
		{
			i++;
			PhoneBook.add_contact(i);
		}	
	}
	return (0);
}