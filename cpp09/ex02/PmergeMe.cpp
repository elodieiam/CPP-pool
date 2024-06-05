#include "PmergeMe.hpp"


/////////////   PARSING  ////////////////////// 
void PMergeMe::checkInput(int ac, char **av)
{
	if (ac < 2)
		throw std::runtime_error("ERROR : Incorrect number of arguments");

	std::string arg;
	long		nb;
	int			element;
	for (int i = 1; i < ac; i++)
	{
		arg = av[i];
		std::string::iterator j;
		for (j = arg.begin(); j != arg.end(); j++)
			if (*j < '0' || *j > '9')
				throw std::out_of_range("ERROR : argument is not a positive integer");
		nb = std::atol(av[i]);
		if (nb > 2147483647)
				throw std::out_of_range("ERROR : argument exceeds integer capacity");
		element = nb;
		_deque.push_back(element);
		_vector.push_back(element);
	}
	if (isSortedVec())
		throw std::runtime_error("Error : the data is already sorted");
	if (hasDouble())
		throw std::runtime_error("Error : there are duplicates");
}

int PMergeMe::hasDouble() const
{
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		if (find(it + 1, _vector.end(), *it) != _vector.end())
			return (1);
	}
	return (0);
}

int PMergeMe::isSortedVec() const
{
	for (unsigned int i = 0; i < _vector.size(); i++)
	{
		for (unsigned int j = i + 1; j < _vector.size(); j++)
		{
			if (_vector[i] > _vector[j])
				return (0);
		}
	}
	return (1);
}



//Constructors & destructors & operator =

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &src)
{
	_deque = src._deque;
	_vector = src._vector;
}
PMergeMe&  PMergeMe::operator = (const PMergeMe &src)
{
	if (this != &src)
	{
		_deque = src._deque;
		_vector = src._vector;
	}
	return (*this);
}
PMergeMe::~PMergeMe()
{
	_deque.clear();
	_vector.clear();
}




