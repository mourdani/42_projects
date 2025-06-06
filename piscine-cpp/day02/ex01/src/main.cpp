/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:07:59 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/13 16:29:10 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <bitset>

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "=========================================" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a rawbit " << a.getRawBits() << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "b rawbit " << b.getRawBits() << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "c rawbit " << c.getRawBits() << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "d rawbit " << d.getRawBits() << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << "=========================================" << std::endl;
	return 0;
}
