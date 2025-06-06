/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:19:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/13 18:44:32 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	 Canonical form:
//	• Default constructor
//	• Copy constructor
//	• Copy assignment operator
//	• Destructor

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    private:
        int _fixed_number; //integer to store the fixed-point number value
        int const static _point = 8; //static constant integer to store the number of fractional bits.

    public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float floatn);
        Fixed(const Fixed &n);
        ~Fixed();

        Fixed &operator=(const Fixed &n);
        bool  operator>(const Fixed &n) const;
        bool  operator<(const Fixed &n);
        bool  operator>=(const Fixed &n);
        bool  operator<=(const Fixed &n);
        bool  operator==(const Fixed &n);
        bool  operator!=(const Fixed &n);
        Fixed operator+(const Fixed &n);
        Fixed operator-(const Fixed &n);
        Fixed operator*(const Fixed &n);
        Fixed operator/(const Fixed &n);

        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);

	int toInt( void ) const;
	float toFloat( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const number );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
