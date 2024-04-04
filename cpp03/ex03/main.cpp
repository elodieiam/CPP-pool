/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:27:00 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/04 15:56:00 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Diamond.hpp"


int main(void)
{
	DiamondTrap Juliette("Juliette");
	ClapTrap 	Cha("Cha");
	ScavTrap	Cam("Cam");
	FragTrap	Elo("Elo");
	DiamondTrap Oxo("Oxo");

	Juliette.attack(Cha.getName());
	Cha.takeDamage(Juliette.getAttackDamage());
	
	Juliette.changeAttackDamage(18);
	Juliette.attack(Cha.getName());
	Cha.takeDamage(Juliette.getAttackDamage());
	
	Cha.beRepaired(23);
	Cha.attack(Elo.getName());
	Elo.takeDamage(Cha.getAttackDamage());
	Elo.highFivesGuys();
	
	Oxo.attack(Cam.getName());
	Cam.takeDamage(Oxo.getAttackDamage());

	Oxo.whoAmI();
	Cam.guardGate();
	Cam.guardGate();

	Cam.attack(Cha.getName());
	Cha.takeDamage(Cam.getAttackDamage());

	Juliette.highFivesGuys();
	Juliette.guardGate();
	Juliette.whoAmI();
}