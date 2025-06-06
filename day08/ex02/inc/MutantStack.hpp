#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <algorithm>
#include <stack>
#include <iterator>
#include <ostream>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {

public:
	typedef typename std::deque<T>::iterator iterator;

	MutantStack() : std::stack<T>() {};
	MutantStack(MutantStack &copy) : std::stack<T>() {*this = copy;};
	virtual ~MutantStack() {};

	MutantStack	&operator=(MutantStack &other) {std::stack<T>::operator=(other); return (*this);};

	iterator	end() {
		return(this->c.end());
		};
	iterator	begin() {return(this->c.begin());};
};

#endif