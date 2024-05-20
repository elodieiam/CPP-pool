#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
int easyfind(T container, int to_find)
{
	typename T::iterator it_find;
	it_find = std::find(container.begin(), container.end(), to_find);
	if (it_find != container.end())
		return (*it_find);
	else
		throw std::runtime_error("The number wasn't found in the container");
}

#endif