#include "../incs/Span.hpp"

Span::Span() : N(10)
{}

Span::~Span()
{}

Span::Span(unsigned int N) : N(N)
{}

Span::Span(const Span &to_copy)
{
	N = to_copy.N;
	vect = to_copy.vect;
}

Span &Span::operator=(const Span &to_copy)
{
	if (this != &to_copy)
	{
		N = to_copy.N;
		vect = to_copy.vect;
	}

	return *this;
}

void Span::addNumber(int num)
{
	if (vect.size() >= N)
		throw VectorIsFullException();
	vect.push_back(num);
}

int Span::shortestSpan() const
{
    if (vect.size() < 2)
        throw NeedMoreElementsException();

    std::vector<int> copy = vect;
    std::sort(copy.begin(), copy.end());

    int minSpan = copy[1] - copy[0];
    for (size_t i = 1; i < copy.size() - 1; ++i)
    {
        int span = copy[i + 1] - copy[i];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

int Span::longestSpan() const
{
	if (vect.size() < 2)
		throw NeedMoreElementsException();

	std::vector<int>::const_iterator min = std::min_element(vect.begin(), vect.end());
	std::vector<int>::const_iterator max = std::max_element(vect.begin(), vect.end());

	return *max - *min;
}

const char *Span::VectorIsFullException::what() const throw()
{
	return "Cannot add more numbers: Span is full.";
}

const char *Span::NeedMoreElementsException::what() const throw()
{
	return "Not enough elements to find a span.";
}
