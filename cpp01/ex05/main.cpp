/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:58:46 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/19 14:00:11 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"
int main()
{
	Harl harl;
	
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("DExxxxxx");
}