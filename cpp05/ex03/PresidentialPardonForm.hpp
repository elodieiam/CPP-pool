/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:45:44 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/06 17:55:12 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm& operator = (const PresidentialPardonForm &other);
	~PresidentialPardonForm(void);

	void perform_exec(void) const;

	private:
	std::string _target;
};

#endif