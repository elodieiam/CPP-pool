/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:28:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 20:45:04 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define SIZE 10

int main()
{
	{
		Cat *cat = new Cat();
	cat->setIdea(2, "hungry");
	cat->setIdea(9, "thirsty");
	cat->setIdea(18, "carpe diem");

	std::cout << cat->getIdea(2) << std::endl;
	std::cout << cat->getIdea(9) << std::endl;
	std::cout << cat->getIdea(18) << std::endl;
	std::cout << cat->getIdea(-18) << std::endl;

	delete cat;
	}
	
	{
		Animal *arr[SIZE];

		for (int i = 0; i < SIZE / 2; i++)
			arr[i] = new Cat();
		for (int i = SIZE / 2; i < SIZE; i++)
			arr[i] = new Dog();
	}
}