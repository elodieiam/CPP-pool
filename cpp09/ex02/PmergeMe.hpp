#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <stdexcept>
#include <exception>
#include <string>
#include <cstdlib> 
#include <iostream>

class PMergeMe
{
	public:
	PMergeMe();
	PMergeMe(const PMergeMe &src);
	PMergeMe& operator = (const PMergeMe &src);
	~PMergeMe();

	void checkInput(int ac, char **av);
	void sortInput(int ac, char **av);
	std::vector<int> sortVector();
	std::vector<std::pair<int, int>> createPairVector();
	std::vector<std::pair<int, int>> sortPairVector(std::vector<std::pair<int, int>> vector);


	private:
	std::list<int> _list;
	std::vector<int> _vector;

};

#endif