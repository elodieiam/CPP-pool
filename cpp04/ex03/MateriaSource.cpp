/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:23:07 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/18 16:14:11 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	// std::cout << "[MateriaSource] : default constructor called" << std::endl;
	
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &materiasource)
{
	// std::cout << "[MateriaSource] : copy constructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (materiasource._inventory[i])
            this->_inventory[i] = materiasource._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	// std::cout << "[MateriaSource] : copy assignment operator called" << std::endl;

	if (this != &other)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		}	
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << "[MateriaSource] : destructor called" << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];	
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			if (this->_inventory[i] == m)
			{
				std::cout << "Error :same materia learned" << std::endl;
				return ;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			// std::cout << "Materia " << m->getType() << " learned." << std::endl;
			return ;
		}
	}
	delete m;
	std::cout << "Inventory is full" << std::endl;
	return ;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type.size())
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			{
				// std::cout << "Materia " << type << " created." << std::endl;
				return (this->_inventory[i]->clone());
			}
		}
		std::cout << "Materia " << type << " not found." << std::endl;
	}
	return (0);
}

