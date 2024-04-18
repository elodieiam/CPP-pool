/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:46:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/18 15:24:10 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	std::cout << "=========================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

{
	const WrongAnimal* i = new WrongCat();
	const WrongAnimal* meta = new WrongAnimal();
	const WrongCat* k = new WrongCat();
	const Animal* j = new Cat();
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "type : " << i->getType();
	i->makeSound();
	std::cout << std::endl;
	std::cout << "type : " << meta->getType();
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "type : " << k->getType();
	k->makeSound();
	std::cout << std::endl;
	std::cout << "type : " << j->getType();
	j->makeSound();
	std::cout << std::endl;



	delete meta;
	delete i;
	delete j;
	delete k;
	std::cout << "=========================================" << std::endl;
}


return (0);
}