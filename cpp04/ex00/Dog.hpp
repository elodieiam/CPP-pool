/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 18:21:33 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog(void);
	Dog (const Dog &other);
	Dog &operator = (const Dog &other);
	~Dog(void);

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif