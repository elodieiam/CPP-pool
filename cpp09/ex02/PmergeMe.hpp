#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <exception>
#include <string>
#include <cstdlib> 
#include <iostream>
#include <algorithm>

class PMergeMe
{
	public:
	PMergeMe();
	PMergeMe(const PMergeMe &src);
	PMergeMe& operator = (const PMergeMe &src);
	~PMergeMe();

	void checkInput(int ac, char **av);
	void sortInput();
	

	



	private:
	std::deque<int> _deque;
	std::vector<int> _vector;

	int _oddNb;

	int isSortedVec() const;
	int hasDouble() const;
	
	//vectors
	void _sortVector();
	void _makePairsVec(std::vector<int> &vbig, std::vector<int> &vsmall);
	void _mergeSortVec(std::vector<int> &vbig, std::vector<int> &vsmall);
	//deque
	
};

#endif