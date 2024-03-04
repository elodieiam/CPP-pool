/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:00:16 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/04 11:38:55 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	cmd_line("");
	int			i, nb_contacts = 0;

	std::cout << "PhoneBook : ADD to create a new contact" << std::endl; //endl ?
	std::cout << "          : SEARCH to find a contact" << std::endl;
	std::cout << "          : EXIT to exit PhoneBook" << std::endl;
	while (1)
	{
		std::cout << ">";
		if (!getline(std::cin, cmd_line))
			return (1);
		if (!cmd_line.compare("EXIT"))
			break ;
		else if (!cmd_line.compare("SEARCH"))
				PhoneBook.display_contact(i - 1, nb_contacts);
		else if (!cmd_line.compare("ADD"))
		{
			if (i == 8)
				i = 0;
			PhoneBook.add_contact(i);
			i++;
			nb_contacts++;
		}	
	}
	return (0);
}
