#include "../inc/Fixed.hpp"
#include <iomanip>

int main( void ) {
	Fixed a;
	Fixed const b(Fixed( 5.05f) / Fixed(2));
	std::cout.width(10); std::cout << "a : " << std::setw(35) << a << std::endl;
	std::cout.width(10); std::cout << "++a : " << std::setw(35) << ++a << std::endl;
	std::cout.width(10); std::cout << "a : " << std::setw(35) <<  a << std::endl;
	std::cout.width(10); std::cout << "a++ : " << std::setw(35) <<  a++ << std::endl;
	std::cout.width(10); std::cout << "a : " << std::setw(35) <<  a << std::endl;
	std::cout.width(10); std::cout << "b : " << std::setw(35) <<  b.toFloat() << std::endl;
	std::cout.width(10); std::cout << "max : " << std::setw(35) <<  Fixed::max( a, b ) << std::endl;
	std::cout.width(10); std::cout << "min : " << std::setw(35) <<  Fixed::min( a, b ) << std::endl;
	std::cout.width(10); std::cout << "a + b : " << std::setw(35) <<  a + b << std::endl;
	std::cout.width(10); std::cout << "a - b : " << std::setw(35) <<  a - b << std::endl;
	std::cout.width(10); std::cout << "a * b : " << std::setw(35) <<  a * b << std::endl;
	std::cout.width(10); std::cout << "a / b : " << std::setw(35) <<  a / b << std::endl;
	return 0;
}

/*
 * output:
	0
	0.00390625
	0.00390625
	0.00390625
	0.0078125
	10.1016
	10.1016
*/
