/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:44:22 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/02 18:32:22 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
 ScavTrap Ma("hi");
 ScavTrap Cleo("Cleoo");
 ClapTrap Jo("liiiiiiiii");

 Ma.attack(Jo.getName());
 Jo.takeDamage(Ma.getAttackDamage());
 Ma.beRepaired(1);
 Ma.guardGate();
 
 Cleo.attack(Ma.getName());
 Ma.takeDamage(Cleo.getAttackDamage());
 Cleo.guardGate();
 Cleo.beRepaired(5);

 
 
 
 Jiji.attack(Hoho.getName());
	Hoho.takeDamage(Jiji.getAttackDamage());
	Jiji.changeAttackDamage(2);
	Jiji.attack(Hoho.getName());
	Hoho.takeDamage(Jiji.getAttackDamage());
	Hoho.beRepaired(1);

	Hoho.changeAttackDamage(4);
	Hoho.attack(Jiji.getName());
	Jiji.takeDamage(Hoho.getAttackDamage());
	Jiji.beRepaired(3);
	Hoho.attack(Jiji.getName());
	Jiji.takeDamage(Hoho.getAttackDamage());
	Hoho.attack(Jiji.getName());
	Jiji.takeDamage(Hoho.getAttackDamage());
	Hoho.attack(Jiji.getName());
	Jiji.takeDamage(Hoho.getAttackDamage());
	Jiji.attack(Hoho.getName());
}