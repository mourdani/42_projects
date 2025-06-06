#include "../inc/Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &copy) {
	*this = copy;
}

Span::~Span() {
	return;
}

Span	&Span::operator=(Span const &other) {
	_N = other._N;
	this->_numbers = other._numbers;
	return (*this);
}

void	Span::addNumber(int x) {
   if (this->_numbers.size() == _N)
        throw std::length_error("Span is full");
    this->_numbers.push_back(x);
}

long    Span::shortestSpan() {
        if (this->_numbers.size() < 2)
            throw std::length_error("Not enough numbers to find span");

        std::sort(this->_numbers.begin(), this->_numbers.end());

        int minSpan = this->_numbers[1] - this->_numbers[0];
        for (unsigned int i = 1; i < this->_numbers.size() - 1; i++)
            minSpan = std::min(minSpan, this->_numbers[i + 1] - this->_numbers[i]);

        return minSpan;
}

long	Span::longestSpan() const {
	if (this->_numbers.size() < 2)
        throw std::length_error("Not enough numbers to find span");

	return this->_numbers.back() - this->_numbers.front();
}

void	Span::addNumbers(unsigned int n) {

	if (n > this->_N || !this->_N)
		throw std::length_error("Span is full");
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++) {
		this->_numbers.push_back(rand() % 50);
	}
}