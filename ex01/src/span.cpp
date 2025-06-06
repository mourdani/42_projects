#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &copy) {
	*this = copy;
}

Span::~Span() {
	return;
}

Span	&Span::operator=(Span const &rhs) {
	_N = rhs._N;
	this->_list = rhs._list;
	return (*this);
}

void	Span::addNumber(int n) {
	if (this->_list.size() == _N)
		throw std::length_error("List is already full.");
	this->_list.push_back(n);
}

long    Span::shortestSpan() {
	if (this->_list.size() < 2)
		throw std::logic_error("Need minimum two numbers to find a span.");
	
	this->_list.sort();

	std::list<int>::iterator next = this->_list.begin();
	std::list<int>::iterator iter = next++;
	std::list<int>::iterator end = this->_list.end();

	long min = std::abs(static_cast<long>(*(next++)) - static_cast<long>(*(iter++)));
	long tmp;
	while (next != end)
	{
		tmp = std::abs(static_cast<long>(*(next++)) - static_cast<long>(*(iter++)));
		if (tmp < min)
			min = tmp;
	}

	return (min);
}

long	Span::longestSpan() const {
	if (this->_list.size() < 2)
		throw std::logic_error("Need minimum two numbers to find a span.");

	long min = *std::min_element(this->_list.begin(), this->_list.end());
	long max = *std::max_element(this->_list.begin(), this->_list.end());
	return (max - min);
}