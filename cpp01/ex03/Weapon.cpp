/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:32:25 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/17 18:55:24 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}