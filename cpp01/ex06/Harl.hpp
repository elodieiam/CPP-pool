/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:04:20 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/19 14:31:58 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);
	
	private:
	void debug (void);
	void info  (void);
	void warning (void);
	void error (void);
};

#endif