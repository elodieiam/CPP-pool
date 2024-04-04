/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:15:23 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/04 12:38:01 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap (const FragTrap &other);
	FragTrap &operator = (const FragTrap &other);
	~FragTrap(void);

	void highFivesGuys(void);
	void attack(const std::string& target);
	
};

#endif