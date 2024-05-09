/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:05:07 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/09 17:53:26 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(std::time(0));
	
	int random = std::rand() % 3;

	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	if (random == 2)
		return (new C);
	return (NULL);
}
void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		return (std::cout << "[pointer] : the object is of type A", (void)0);
		
	if (dynamic_cast<B *>(p))
		return (std::cout << "[pointer] : the object is of type B", (void)0);
	
	if (dynamic_cast<C *>(p))
		return (std::cout << "[pointer] : the object is of type C", (void)0);

	if (dynamic_cast<Base *>(p))
		return (std::cout << "[pointer] : the object is of type base", (void)0);
}
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		return (std::cout << "[reference] : the object is of type A", (void)0);
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<B &>(p);
		return (std::cout << "[reference] : the object is of type B", (void)0);
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<C &>(p);
		return (std::cout << "[reference] : the object is of type C", (void)0);
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<Base &>(p);
		return (std::cout << "[reference] : the object is of type Base", (void)0);
	}
	catch(const std::exception& e){}
}

int main()
{
	srand (time(NULL));
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";
	
	std::cout << green << "Simple tests : " << reset << std::endl << std::endl;
	std::cout << green << "With A : " << reset << std::endl << std::endl;

	Base *a = new A;
	identify(a);
	identify(*a);
	delete a;
	std::cout << std::endl << std::endl;

	std::cout << green << "With B : " << reset << std::endl << std::endl;

	Base *b = new B;
	identify(b);
	identify(*b);
	delete b;
	std::cout << std::endl << std::endl;

	std::cout << green << "With C : " << reset << std::endl << std::endl;

	Base *c = new C;
	identify(c);
	identify(*c);
	delete c;
	std::cout << std::endl << std::endl;

	std::cout << green << "With base : " << reset << std::endl << std::endl;

	Base *base = new Base;
	identify(base);
	identify(*base);
	delete base;
	std::cout << std::endl << std::endl;

	std::cout << green << "Random tests : " << reset << std::endl << std::endl;

	Base *p;
		p = generate();
		identify(p);
		std::cout << std::endl;
		identify(*p);
		std::cout << std::endl;
		delete p;
}