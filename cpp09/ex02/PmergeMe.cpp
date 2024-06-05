#include "PmergeMe.hpp"


/////////////   PARSING  ////////////////////// 
void PMergeMe::checkInput(int ac, char **av)
{
	if (ac < 2)
		throw std::runtime_error("ERROR : Incorrect number of arguments");
	
	_size = ac - 1;
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
	for (unsigned int i = 0; i < _size; i++)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
}

/////////// VECTOR //////////////////////

void PMergeMe::_sortVector()
{
	std::vector<int> vbig;
	std::vector<int> vsmall;
	_makePairsVec(vbig, vsmall);
	_mergeSortVec(vbig, vsmall);

	if (_oddNb >= 0)
		vsmall.push_back(_oddNb);
	_vector.clear();
	for (unsigned int i = 0; i < vbig.size(); i++)
		_vector.push_back(vbig[i]);
	_vector.insert(_vector.begin(), vsmall[0]);
	
	if (_vector.size() == _size)
		return ;
	//on trouve l'indice auquel on peut l'insérer sans changer l'ordre du vecteur
	std::vector<int>::iterator it = std::upper_bound(_vector.begin(), _vector.end(), vsmall[1]);
	
	_vector.insert(it, vsmall[1]);
	//high et low déterminent la plage de recherche pour trouver l'indice optimal où insérer la valeur
	//mid = indice médian de la plage de recherche pour diviser la plage en 2 et choisir dans quelle moitié poursuivre la recherche
	//index = l'indice dans vsmall à partir duquel on veut insérer les valeurs. on insère ensuite toutes les valeurs dont l'indice est < à index
	int jacob = 3;
	unsigned int jacobN_1 = 1;
	int low = 0;
	int high = _vector.size() - 1;
	unsigned int mid = low + (high - low) / 2;
	unsigned int index = jacob;
	
	while (_vector.size() != _size)
	{
		//si index > taille vsmall mais qu'il reste encore des choses à insérer on parcourt vsmall à partir d'un autre index
		if (index >= vsmall.size() && _vector.size() != _size)
		{
			index = jacobN_1 + 1;
			while (index < vsmall.size())
			{
				_dichotomyInsert(high, low, mid, index, vsmall);
				index++;
			}
		}
		if (_vector.size() == _size)
			break ;
		//on traite les élts par ordre décroissant de index à jacobN_1
		while (index > jacobN_1)
		{
			_dichotomyInsert(high, low, mid, index, vsmall);
			index--;
		}
		//màj de la suite de jacobsthal
		int tmpJacob = jacob;
		jacob = tmpJacob + 2 * jacobN_1;
		jacobN_1 = tmpJacob;
		index = jacob;
	}
}

/*
Insertion dichotomique d'un élt de vsmall en indice index dans _vector
recherche binaire pour trouver la pos d'insertion correcte pour maintenir l'ordre de tri du vecteur
*/
void PMergeMe::_dichotomyInsert(int high, int low, unsigned int mid, unsigned int &index, std::vector<int> &vsmall)
{
	while ((high - low) > 1)
	{
		if (_vector[mid] < vsmall[index]) //on va dans la moitié droite
		{
			low = mid;
			mid = low + (high - low) / 2;
		}
		else if (_vector[mid] > vsmall[index]) //moitié gauche
		{
			high = mid;
			mid = low + (high - low) / 2;
		}
	}
	//l'élt à insérer est + petit que tous les élts actuels de _vector
	if (mid == 0 && vsmall[index] < _vector[mid])
		_vector.insert(_vector.begin(), vsmall[index]);
	//l'élet à insérer est + grand que tous les autres
	else if (mid == (_vector.size() - 2) && (vsmall[index] > _vector[mid] && vsmall[index] > _vector[mid + 1]))
		_vector.insert(_vector.begin() + mid + 2, vsmall[index]);
	else
		_vector.insert(_vector.begin() + mid + 1, vsmall[index]);
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
		
		vsr.assign(vsmall.begin() + mid, vsmall.end());


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




