/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:44:51 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/03 16:02:53 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap Hilo("Hilo");
	FragTrap Gege(Hilo);
	ClapTrap Juju("Juju");
	ScavTrap Lo("Lo");
	ScavTrap Mo;
	Mo = Lo;

	Gege.highFivesGuys();
	Gege.attack(Juju.getName());
	Juju.takeDamage(Gege.getAttackDamage());
	
	Lo.guardGate();
	Lo.guardGate();
	
	Lo.attack(Mo.getName());
	Mo.takeDamage(Lo.getAttackDamage());
	Lo.beRepaired(3);
	Mo.beRepaired(2);
}