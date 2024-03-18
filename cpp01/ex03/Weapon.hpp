/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:15:37 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/17 18:50:57 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public:
	Weapon(std::string type);
	~Weapon(void);
	const std::string& getType(void);
	void 			setType(std::string newType);		
	
	private:
	std::string		_type;
};

#endif