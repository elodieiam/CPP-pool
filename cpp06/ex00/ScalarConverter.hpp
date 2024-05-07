/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:29:45 by elrichar          #+#    #+#             */
/*   Updated: 2024/05/07 16:07:09 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
	static void convert(std::string str);
	
	private:
	ScalarConverter(void);
	ScalarConverter (const ScalarConverter &other);
	ScalarConverter &operator = (const ScalarConverter &other);
	~ScalarConverter(void);
	
};

bool is_specific(std::string str);
bool is_char(std::string str);
bool is_int(std::string str);



void display_specific(std::string str);
void display_char(std::string str);
void display_int(std::string str);


void display_error(void);



#endif