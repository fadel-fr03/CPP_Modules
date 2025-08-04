#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

class NotFoundException : public std::exception
{
	public:
    	virtual const char* what() const throw()
		{
        	return "Number not found in container.";
    	}
};

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif
