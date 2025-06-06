/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:02:13 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/28 15:02:18 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/template.hpp"

int main( void ) {

std::cout << "============= INT ===============" << std::endl;
int a = 6;
int b = 3;
std::cout << "a = " << a << ", b = " << b << std::endl;

std::cout << "============ SWAP =============" << std::endl;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;

std::cout << "============================" << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl << std::endl;

std::cout << "======= STD::STRING ========" << std::endl;
std::string c = "string";
std::string d = "string2";
std::cout << "c = " << c << ", d = " << d << std::endl;

std::cout << "============ SWAP =============" << std::endl;
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;

std::cout << "============================" << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl << std::endl;

std::cout << "=========== OBJECT ============" << std::endl;
Example x(99), y(44);
std::cout << "x = " << x << ", y = " << y << std::endl;

std::cout << "============ SWAP =============" << std::endl;
swap(x, y);
std::cout << "x = " << x << ", y = " << y << std::endl;

std::cout << "============================" << std::endl;
std::cout << "min( y, z ) = " << ::min( x , y ) << std::endl;
std::cout << "max( y, z ) = " << ::max( x , y ) << std::endl;


return 0;
}
