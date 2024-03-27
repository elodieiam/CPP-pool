/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:56:28 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/27 16:23:58 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
	public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap (const ClapTrap &other);
	ClapTrap &operator = (const ClapTrap &other);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int	getAttackDamage(void) const;
	void changeAttackDamage(int newAttackDamage);


	private:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif