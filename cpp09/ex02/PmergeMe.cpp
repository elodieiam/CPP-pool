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

//////////// MERGE SORT /////////////////////
void PMergeMe::sortInput()
{
	_sortVector();
}

/////////// VECTOR //////////////////////

void PMergeMe::_sortVector()
{
	std::vector<int> vbig;
	std::vector<int> vsmall;
	_makePairsVec(vbig, vsmall);
	_mergeSortVec(vbig, vsmall);
}

void PMergeMe::_mergeSortVec(std::vector<int> &vbig, std::vector<int> &vsmall)
{
	if (vbig.size() > 1)
	{
		int mid = vbig.size() / 2;

		std::vector<int> vbl;
		std::vector<int> vbr;
		std::vector<int> vsl;
		std::vector<int> vsr;

		vbl.assign(vbig.begin(), vbig.begin() + mid);
		vbr.assign(vbig.begin() + mid, vbig.end());
		vsl.assign(vsmall.begin(), vsmall.begin() + mid);
		vsr.assign(vsmall.begin() + mid, vsmall.begin());

		_mergeSortVec(vbl, vsl);
		_mergeSortVec(vbr, vsr);
		
		size_t i = 0, j = 0, k = 0;
		while (i < vbl.size() && j < vbr.size())
		{
			if (vbl[i] < vbr[j])
			{
				vbig[k] = vbl[i];
				vsmall[k] = vsl[i];
				i++; 
			}
			else
			{
				vbig[k] = vbr[j];
				vsmall[k] = vsr[j];
				j++;
			}
			k++;
		}
		while (i < vbl.size())
		{
			vbig[k] = vbl[i];
			vsmall[k] = vsl[i];
			i++;
			k++;
		}
		while (j < vbr.size())
		{
			vbig[k] = vbr[j];
			vsmall[k] = vsr[j];
			j++;
			k++;
		}
	}
}


void PMergeMe::_makePairsVec(std::vector<int> &vbig, std::vector<int> &vsmall)
{
	if (_vector.size() % 2)
	{
		_oddNb = _vector[_vector.size() - 1];
		_vector.pop_back();
	}
	for (unsigned int i = 0; i < _vector.size(); i += 2)
	{
		if (_vector[i] < _vector[i + 1])
		{
			vsmall.push_back(_vector[i]);
			vbig.push_back(_vector[i + 1]);
		}
		else
		{
			vsmall.push_back(_vector[i + 1]);
			vbig.push_back(_vector[i]);
		}
	}
}


//Constructors & destructors & operator =

PMergeMe::PMergeMe() : _oddNb(-1) {}

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




