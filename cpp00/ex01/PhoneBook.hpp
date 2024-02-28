/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:28 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/28 18:41:23 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	public:
	PhoneBook();
	void	add_contact(int	index);
	void	display_contact(int index, int nb_contacts);
	
	private:
	Contact	Repertoire[8];
};

#endif