/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:19:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/07 23:22:56 by mourdani         ###   ########.fr       */
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

class Fixed {
    private:
        int _fixed_number; //integer to store the fixed-point number value
        int const static _point = 8; //static constant integer to store the number of fractional bits.

    public:
        Fixed();
        Fixed(const Fixed &n);
        Fixed &operator=(const Fixed &n);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const number );

};
