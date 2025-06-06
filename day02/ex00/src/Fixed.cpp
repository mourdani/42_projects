/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:19:48 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/07 23:19:50 by mourdani         ###   ########.fr       */
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

// Destructor
Fixed::~Fixed(){
    std::cout << "Deconstructor called\n";
};

// Operator overload
Fixed &Fixed::operator=(const Fixed &n){
    std::cout << "Assignation operator called\n";
    setRawBits(n.getRawBits());
    return *this;
}

// Returns the raw value of the fixed-point value
int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called\n";
    return this->_fixed_number;

}

// Sets the raw value of the fixed-point number
void Fixed::setRawBits( int const number ){
    this->_fixed_number = number;
}
