/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:28:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/18 15:26:59 by elrichar         ###   ########.fr       */
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
	std::cout << std::endl;

	cat->setIdea(2, "hungry");
	cat->setIdea(9, "thirsty");
	cat->setIdea(18, "carpe diem");

	std::cout << cat->getIdea(2) << std::endl;
	std::cout << cat->getIdea(9) << std::endl;
	std::cout << cat->getIdea(18) << std::endl;
	std::cout << cat->getIdea(-18) << std::endl;

	delete cat;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "=========================================" << std::endl;

	}

	{
		Animal *dog = new Dog();
		std::cout << std::endl;

		dog->setIdea(19, "fluctuat nec mergitur");
		dog->setIdea(56, "pluie");
		dog->setIdea(0, "camara");
		dog->setIdea(-27, "jjjj");
		dog->setIdea(56, "rain");

		std::cout << dog->getIdea(3) << std::endl;
		std::cout << dog->getIdea(19) << std::endl;
		std::cout << dog->getIdea(56) << std::endl;
		std::cout << dog->getIdea(0) << std::endl;
		std::cout << dog->getIdea(-12) << std::endl;
		std::cout << dog->getIdea(56) << std::endl;

		std::cout << std::endl;
		delete dog;
		std::cout << std::endl;

	}
	
	{
		Animal *arr[SIZE];
		std::cout << std::endl;
		std::cout << std::endl;


		for (int i = 0; i < SIZE / 2; i++)
			arr[i] = new Cat();
		std::cout << std::endl;
		std::cout << std::endl;
		
		for (int i = SIZE / 2; i < SIZE; i++)
			arr[i] = new Dog();
		std::cout << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < SIZE; i++)
			arr[i]->makeSound();
		std::cout << std::endl;
		std::cout << std::endl;
		
		for (int i = 0; i < SIZE; i++)
			delete arr[i];
	}
	return (0);
}