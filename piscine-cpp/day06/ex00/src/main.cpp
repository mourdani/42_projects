/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:18:21 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/25 01:18:23 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Conversion.hpp"

#include <string>
#include <iostream>
#include <cstdlib>

int main(int ac, char **av) {
	if (ac != 2 || av[1][0] == '\0') {
        std::cerr << "Error: invalid argument." << std::endl;
		return (1);
	}

	Conversion converter;
	std::string literal = static_cast<std::string>(av[1]);
	std::string type = converter.find_type(literal); 

	if (type == "int") {
		int i = std::atoi(literal.c_str());
		converter.print(i);
	}
	else if (type == "float") {
		float f = std::atof(literal.c_str());
		converter.print(f);
	}
	else if (type == "double") {
		double d = static_cast<double>(std::atof(literal.c_str()));
		converter.print(d);
	}
	else if (type == "char") {
		char c = literal.at(0);
		converter.print(c);
	}
	else if (type == "invalid") {
		std::cout << "Invalid character input" << std::endl;
	}
	return (0);
}
