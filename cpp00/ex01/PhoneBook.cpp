/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:47:55 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/28 18:41:41 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

PhoneBook::PhoneBook() {};

/*this est un pointeur implicite sur l'objet sur lequel est appelé la méthode.
On accède à un élément du tab appartenant à l'objet courant sur lequel la méthode est appelée.
 */
/* Phonebook:: indique que la fonction qui suit fait partie de la classe PhoneBook.
"::" sert à définir les méthodes hors de la définition de la classe
*/
void	PhoneBook::add_contact(int index)
{
	this->Repertoire[index].New_contact(index); //on accède à la méthode de l'objet contact
	//qui est dans l'objet PhoneBook.
	//on va dans répertoire qui contient 8 objets de type contact
}

int	check_searched(std::string str)
{
	if (str.size() > 1)
	{
		std::cout << "Error in index format" << std::endl;
		return (1);
	}
	if (str[0] >= '0' && str[0] <= '7')
		return (0);
	std::cout << "Error in index format" << std::endl;
	return (1);
}

void	PhoneBook::display_contact(int	index, int nb_contacts)
{
	std::string	str("");
	
	if (nb_contacts == 0)
	{
		std::cout << "no contact yet ! PhoneBook is empty !" << std::endl;
		return ;
	}
	this->Repertoire[index].display_contact();
	while (str.empty() || check_searched(str))
	{
		std::cout << "Enter the index of the contact to be displayed (0 to 7): \n>";
		if (!getline(std::cin, str))
			return ;
	}
	if (!check_searched(str))
		this->Repertoire[str[0] - 48].display_specific();
}
