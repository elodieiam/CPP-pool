/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:40:08 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/04 15:52:36 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap (const ScavTrap &other);
	ScavTrap &operator = (const ScavTrap &other);
	~ScavTrap(void);

	void attack(const std::string& target);
	void guardGate();
};


#endif