#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <cstdlib>
#include <exception>
#include <iostream>

class Span {

private:
	std::vector<int> _numbers;
	unsigned int _N;

public:
	Span(unsigned int N);
	Span(Span const &copy);
	virtual ~Span();

	Span	&operator=(Span const &other);

	void	addNumber(int x);
	long	shortestSpan();
	long	longestSpan() const;
	void	addNumbers(unsigned int n);

};

#endif