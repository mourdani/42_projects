#ifndef  ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.tpp"

class Example {
public:
	Example( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

#endif
