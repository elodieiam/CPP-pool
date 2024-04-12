/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:46:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/12 17:47:15 by elrichar         ###   ########.fr       */
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
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;
std::cout << "=========================================" << std::endl;
}

{
const WrongAnimal* meta = new WrongAnimal();
const WrongAnimal* i = new WrongCat();
const WrongCat* k = new WrongCat();
const Animal* j = new Cat();

std::cout << "type : " << i->getType() << std::endl;
i->makeSound();
std::cout << "type : " << meta->getType() << std::endl;
meta->makeSound();
std::cout << "type : " << k->getType() << std::endl;
k->makeSound();
std::cout << "type : " << j->getType() << std::endl;
j->makeSound();


delete meta;
delete i;
delete j;
delete k;
std::cout << "=========================================" << std::endl;
}


return (0);
}