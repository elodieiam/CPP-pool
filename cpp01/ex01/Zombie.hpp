/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:24:26 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/17 18:34:10 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	set_name(std::string str);

	private:
	std::string		name;	
};

Zombie* zombieHorde( int N, std::string name );

#endif