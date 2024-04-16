/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:28:43 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/16 17:41:44 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class AMateria
{
	protected:
	std::string _type;

	public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const &amateria);
	AMateria &operator=(AMateria const &amateria);
	virtual ~AMateria(void);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif