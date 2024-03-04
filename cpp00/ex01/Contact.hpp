/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:44:58 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/04 12:03:11 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
	Contact(void);
	~Contact(void);
	void	New_contact(int index);
	void	display_contact(void);
	void	display_specific(void);
	void	trunc_display(std::string str);
	void	setIndex(int index);
	void	setFirstName(void);
	void	setLastName(void);
	void	setNickname(void);
	void	setPhoneNumber(void);
	void	setDarkestSecret(void);
	
	private:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};



#endif