/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:58:58 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/17 18:06:28 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
	Character(void);
	Character(std::string name);
	Character(Character const &character);
	Character &operator=(Character const &character);
	~Character(void);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria *leaveMateria(int idx);

	private:
	std::string _name;
	AMateria    *_inventory[4];
};

#endif

