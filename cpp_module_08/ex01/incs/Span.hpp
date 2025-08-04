#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
    	unsigned int N;
    	std::vector<int> vect;

	public:
    	// Default constructor
    	Span();

    	// Destructor
    	~Span();

    	// Parameterized constructor
    	Span(unsigned int N);

    	// Copy constructor
    	Span(const Span &to_copy);

    	// Copy assignment operator
    	Span &operator=(const Span &to_copy);

    	// Add a number
    	void addNumber(int num);

    	// Add a range of numbers using iterators
    	template <typename InputIterator>
    	void addRange(InputIterator begin, InputIterator end)
    	{
    	    if (static_cast<unsigned int>(vect.size() + std::distance(begin, end)) > N)
        	    throw VectorIsFullException();
        	vect.insert(vect.end(), begin, end);
    	}

    	// Return the spans
    	int shortestSpan() const;
    	int longestSpan() const;

    	// Exceptions
    	class VectorIsFullException : public std::exception
    	{
    	public:
        	virtual const char *what() const throw();
    	};

    	class NeedMoreElementsException : public std::exception
    	{
    	public:
    	    virtual const char *what() const throw();
    	};
};

#endif
