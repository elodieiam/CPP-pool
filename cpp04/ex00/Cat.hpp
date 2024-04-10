/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:39:20 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/10 15:49:36 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat(void);
	Cat (const Cat &other);
	Cat &operator = (const Cat &other);
	~Cat(void);

	void makeSound(void) const;
	std::string getType(void) const;

	protected:
	std::string _type;
};

#endif