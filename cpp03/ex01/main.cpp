/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:44:22 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/04 15:49:58 by elrichar         ###   ########.fr       */
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
 Ma.guardGate();

 
 Cleo.attack(Ma.getName());
 Ma.takeDamage(Cleo.getAttackDamage());
 Cleo.guardGate();
 Cleo.beRepaired(5);
 Jo.attack(Ma.getName());
 Ma.takeDamage(Jo.getAttackDamage());
 Jo.attack(Cleo.getName());
 Cleo.takeDamage(Jo.getAttackDamage());
 


}