/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/16 18:12:33 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
	Dog(void);
	Dog (const Dog &other);
	Dog &operator = (const Dog &other);
	~Dog(void);

	void makeSound(void) const;
	std::string getType(void) const;

	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;

	private:
	Brain *_brain;
};

#endif