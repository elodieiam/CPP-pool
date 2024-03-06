/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:28 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/06 13:34:30 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(int	index);
	void	display_contact(int index, int nb_contacts);
	
	private:
	Contact	Repertoire[8];
};

#endif