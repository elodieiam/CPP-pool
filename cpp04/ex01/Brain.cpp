/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:33:24 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 20:36:30 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "nothing";
}

Brain::Brain (const Brain &other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator = (const Brain &other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Error : incorrect index in setIdea function from Brain class" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Error : incorrect index in getIdea function from Brain class" << std::endl;
		return ("NULL");
	}
	return (this->ideas[index]);
}
