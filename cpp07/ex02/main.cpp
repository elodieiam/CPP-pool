/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:43:21 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/12 17:21:18 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";

	std::cout << green << "Emtpy array test : " << reset << std::endl;
	Array<int> emptyarr;

	
	std::cout << green << "Tests with default values : " << reset << std::endl;

	Array<int> tab(3);
	for (unsigned int i = 0; i < 3; i++)
		std::cout << tab[i] << std::endl;

	std::cout << green << "Tests with personalized values : " << reset << std::endl;
	for (unsigned int i = 0; i < 3; i++)
	{
		tab[i] = 4;	
		std::cout << tab[i] << std::endl;
	}

	std::cout << green << "Out of range index : " << reset << std::endl;

	try 
	{
		std::cout << tab[17] << std::endl;
	}
	catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	
	std::cout << green << "Modify data : " << reset << std::endl;
	tab[0] = 17;
	tab[1] = 18;
	tab[2] = 20;

	std::cout << green << "Copy constructor : " << reset << std::endl;
	Array<int> tab2(tab);
	for (unsigned int i = 0; i < 3; i++)
		std::cout << tab2[i] << std::endl;

	std::cout << green << "Copy operator : " << reset << std::endl;
	Array<int> tab3(4);
	tab3 = tab2;
	for (unsigned int i = 0; i < 3; i++)
		std::cout << tab3[i] << std::endl;

	std::cout << green << "Const objects : " << reset << std::endl;
	const Array<int> tab4(5);
	for (unsigned int i = 0; i < 3; i++)
		std::cout << tab4[i] << std::endl;
	// tab4[2] = 44;
	
}



// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }