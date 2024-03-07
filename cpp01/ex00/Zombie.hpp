/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:53:45 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/07 16:26:47 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);

	private:
	std::string		name;	
};

Zombie	*newZombie (std::string name);
void	randomChump (std::string name);

#endif