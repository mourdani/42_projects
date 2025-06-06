/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 03:03:25 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/02 02:18:07 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";	// String
	std::string * stringPTR = &string;		// Pointer to string
	std::string & stringREF = string;		// Reference to string

	// string and stringREF have the same adresse and not stringPTR
	std::cout << "Adresse of string: " << &string << std::endl;
	std::cout << "Adresse stored in stringPTR: " << stringPTR << std::endl;
	std::cout << "Adresse of stringREF: " << &stringREF << std::endl;
	
	// All have the same value
	std::cout << "string: " << string << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	
	return 0;
}
