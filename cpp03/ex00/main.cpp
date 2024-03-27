/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:07:47 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/27 16:27:24 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Jiji("Jiji");
	ClapTrap Hoho("Hoho");

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