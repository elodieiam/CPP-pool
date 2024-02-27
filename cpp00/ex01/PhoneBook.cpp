/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:47:55 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/27 17:30:21 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

/*this est un pointeur implicite sur l'objet sur lequel est appelé la méthode.
On accède à un élément du tab appartenant à l'objet courant sur lequel la méthode est appelée.
 */
/* Phonebook:: indique que la fonction qui suit fait partie de la classe PhoneBook.
"::" sert à définir les méthodes hors de la définition de la classe
*/
void	PhoneBook::add_contact(int index)
{
	this->Repertoire[index - 1].New_contact(index); //on accède à la méthode de l'objet contact
	//qui est dans l'objet PhoneBook.
	//on va dans répertoire qui contient 8 objets de type contact
}