#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

#include <list>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <cstdlib>
#include <exception>
#include <iostream>

class Span {

private:
	unsigned int	_N;
	std::list<int>	_list;

public:
	Span(unsigned int N);
	Span(Span const &copy);
	virtual ~Span();

	Span	&operator=(Span const &rhs);

	void	addNumber(int n);
	long	shortestSpan();
	long	longestSpan() const;

	template <typename Iter>
	void	addNumber(Iter begin, Iter end) {
		int sizeLeft = static_cast<int>(_N) - static_cast<int>(_list.size());
		if (std::distance(begin, end) > sizeLeft)
			throw std::length_error("Tried to add too many ints to list.");
		else
			_list.insert(_list.begin(), begin, end);
	}
};

#endif