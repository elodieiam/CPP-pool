/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:28:37 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/17 18:41:29 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA(std::string name, Weapon& weaponA);
	~HumanA(void);
	void attack(void) const;

	private:
	std::string _name;
	Weapon 		&_weaponA;
};

#endif