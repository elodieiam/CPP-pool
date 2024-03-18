/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:52:27 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/18 19:14:27 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <cstddef>

void	replace_str(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2)
{
	std::string line;
	size_t 		i;
	size_t		j;
	
	while (std::getline(infile, line))
	{
		i = 0;
		while (i < line.size())
		{
			j = line.find(s1.c_str(), i);
			if (j != std::string::npos && !s1.empty())
			{
				outfile << line.substr(i, j - i) << s2;
				i = j + s1.size();
			}
			else
			{
				outfile << line.substr(i, line.size() - i);
				break;
			}
		}
		outfile << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "wrong number of args" << std::endl, 1);
		
	std::string filename		 = av[1];
	std::string s1		 		 = av[2];
	std::string s2				 = av[3];
	std::string outfile_name	 = av[1];
	outfile_name.append(".replace");
	
	std::ifstream	infile(filename.c_str());
	if (!infile.is_open())
		return (std::cerr << "error in file opening" << std::endl, 1);
	
	std::ofstream 	outfile(outfile_name.c_str());
	if (!outfile.is_open())
		return (std::cerr << "error in file opening" << std::endl, 1);
	
	replace_str(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	return (0);
}