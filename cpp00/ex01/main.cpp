/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:00:16 by elrichar          #+#    #+#             */
/*   Updated: 2024/08/27 14:29:27 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "Wrong number of arguments !" << std::endl;
		return 1;
	}
	PhoneBook	PhoneBook;
	std::string	cmd_line("");
	int			i = 0, nb_contacts = 0;

	std::cout << "PhoneBook : ADD to create a new contact" << std::endl;
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
				PhoneBook.display_contact(nb_contacts);
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
