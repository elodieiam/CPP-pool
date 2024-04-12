/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:39:20 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 20:20:29 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
	Cat(void);
	Cat (const Cat &other);
	Cat &operator = (const Cat &other);
	~Cat(void);

	void makeSound(void) const;
	std::string getType(void) const;

	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;

	private:
	Brain *_brain;
};

#endif