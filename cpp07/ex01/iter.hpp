/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:00:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/10 18:40:32 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename Type>
void iter(Type *addr, int len, void (*fct)(Type &a))
{
	if (!addr || !fct)
		return ;
	for (int i = 0; i < len; i++)
		fct(addr[i]);
}

template <typename Type>
void print(Type &a)
{
	std::cout << a << std::endl;
}

#endif