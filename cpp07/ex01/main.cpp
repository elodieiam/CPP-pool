/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:13:23 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/10 18:36:41 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::string green = "\033[1;32m";
	std::string reset = "\033[0m";
	
	std::cout << green << "Tests with ints : " << reset << std::endl;

	int arr[4] = {2, 4, 6, 8};
	iter(arr, 4, &print);
	std::cout << std::endl << std::endl;

	std::cout << green << "Tests with strings : " << reset << std::endl;
	std::string arr1[4] = {"bonjour", "je", "m'appelle", "Elodie"};
	iter(arr1, 4, print);
	std::cout << std::endl << std::endl;

	std::cout << green << "Tests with floats : " << reset << std::endl;
	float arr2[8] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8};
	iter(arr2, 8, print);
	std::cout << std::endl << std::endl;


}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }


// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print);
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }