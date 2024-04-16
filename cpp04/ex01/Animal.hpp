/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:08:02 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/15 20:08:58 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
	Animal(void);
	Animal (const Animal &other);
	Animal &operator = (const Animal &other);
	virtual ~Animal(void);

	virtual void makeSound(void) const;
	virtual std::string getType(void) const;

	virtual void setIdea(int index, std::string idea);
	virtual std::string getIdea(int index) const;

	protected:
	std::string _type;
};

#endif