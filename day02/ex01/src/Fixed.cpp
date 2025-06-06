/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:19:48 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/08 02:24:02 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Default constructor 
Fixed::Fixed(): _fixed_number(0){
	std::cout << "Default constructor called\n";
};

// Copy constructor 
Fixed::Fixed(const Fixed &n){
	std::cout << "Copy constructor called\n";
	*this = n;
}

// Int constructor 
Fixed::Fixed(const int integer): _fixed_number(integer << this->_point) {
	std::cout << "Int constructor called\n";
};

// Float constructor 
Fixed::Fixed(const float fnumber): _fixed_number(roundf(fnumber * (1 << this->_point))) {
	std::cout << "Float constructor called\n";
};

// Destructor
Fixed::~Fixed(){
	std::cout << "Deconstructor called\n";
};

// Operator overload
Fixed &Fixed::operator=(const Fixed &n){
	std::cout << "Assignation operator called\n";
	setRawBits(n.getRawBits());
	return *this;
};


std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

// Returns the raw value of the fixed-point value
int Fixed::getRawBits( void ) const{
	return this->_fixed_number;

};

// Sets the raw value of the fixed-point number
void Fixed::setRawBits( int const number ){
	this->_fixed_number = number;
};

int Fixed::toInt( void ) const {
	return (this->_fixed_number >> this->_point);
};

float Fixed::toFloat( void ) const {
	return ((float)this->_fixed_number / (1 << this->_point));
};
