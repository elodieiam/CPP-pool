#include "PmergeMe.hpp"
	
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
		_list.push_back(element);
		_vector.push_back(element);
	}
}

void PMergeMe::sortInput(int ac, char **av)
{
	_vector = sortVector();
}

std::vector<std::pair<int, int>> PMergeMe::createPairVector()
{
	std::vector<std::pair<int, int>> pairVector;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		std::vector<int>::iterator it2 = it;
		it2++;
		if (it2 != _vector.end()) //paire normale (nombre pair d'éléments)
		{
			pairVector.push_back(std::make_pair(*it, *it2));
			it++;
		}
		else //"fausse paire" avec (-1) (nombre impair d'éléments)
			pairVector.push_back(std::make_pair(*it, -1));
	}

	for (std::vector<std::pair<int, int>>::iterator it = pairVector.begin(); it != pairVector.end(); it++)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

std::vector<std::pair<int, int>> PMergeMe::sortPairVector(std::vector<std::pair<int, int>> vector)
{
	std::vector<std::pair<int, int>> sortedVector;
	std::vector<std::pair<int, int>>::iterator it_tmp;
	int min1;
	int min2;

	while (!vector.empty())
	{
		min1 = 0;
		min2 = 2147483647;
		for (std::vector<std::pair<int, int>>::iterator it = vector.begin(); it != vector.end(); it++)
		{
			if (it->second < min2)
			{
				min1 = it->first;
				min2 = it->second;
				it_tmp = it;
			}
		}
		vector.erase(it_tmp);
		sortedVector.push_back(std::make_pair(min1, min2));
	}
	return (sortedVector);
}

/****Etape 1 :
 * On crée un vector avec des paires de ints comme éléments
 * On le remplit en appariant chaque nombre avec celui qui le suit immédiatement
 * Puis on trie chaque paire par ordre croissant (mais les paires elles-mêmes sont dans le désordre)
 * Puis on trie les paires par ordre croissant du + grand élément de chaque paire
*/
std::vector<int> PMergeMe::sortVector()
{
	if (_vector.empty() || _vector.size() == 1)
		return _vector;

	std::vector<std::pair<int, int>> pairVector;
	pairVector = createPairVector();
	pairVector = sortPairVector(pairVector);

	
}



PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &src)
{
	_list = src._list;
	_vector = src._vector;
}
PMergeMe&  PMergeMe::operator = (const PMergeMe &src)
{
	if (this != &src)
	{
		_list = src._list;
		_vector = src._vector;
	}
	return (*this);
}
PMergeMe::~PMergeMe()
{
	_list.clear();
	_vector.clear();
}

