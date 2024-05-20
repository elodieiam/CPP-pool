#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack(void) {}
	MutantStack(MutantStack const & src){ *this = src; }

	~MutantStack(void){}

	MutantStack & operator=(MutantStack const & src)
	{ 
		if (this != &src)
			*this = src;
		return (*this);
	}
	
	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() {return this->c.rbegin();}
	reverse_iterator rend() {return this->c.rend();}
};

#endif