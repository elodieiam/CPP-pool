/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:48:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 18:14:02 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
	WrongAnimal(void);
	WrongAnimal (const WrongAnimal &other);
	WrongAnimal &operator = (const WrongAnimal &other);
	virtual ~WrongAnimal(void);

	void makeSound(void) const;
	std::string getType(void) const;

	protected:
	std::string _type;
};

#endif