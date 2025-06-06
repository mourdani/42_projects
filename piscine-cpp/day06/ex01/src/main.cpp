/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:47:58 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/25 01:48:00 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

typedef struct	s_Data {
	std::string	x;
	int			y;
	float		z;
}				Data;

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

int main(void) {
	Data *a = new Data();
	Data *deser_a;
	uintptr_t ser_a;
	std::cout << "==========================" << std::endl;

	a->x = "test";
	a->y = 999;
	a->z = 99.9;
	std::cout	<< "x: " << a->x << std::endl;
	std::cout	<< "y: " << a->y << std::endl;
	std::cout	<< "z: " << a->z << std::endl << std::endl;
	

	std::cout << "==== Serialization: ====" << std::endl;
	ser_a = serialize(a);
	std::cout << ser_a << std::endl << std::endl;

	
	std::cout << "====  Deserialization: ====" << std::endl;
	deser_a = deserialize(ser_a);
    std::cout	<< "x: " << deser_a->x << std::endl;
	std::cout	<< "y: " << deser_a->y << std::endl;
	std::cout	<< "z: " << deser_a->z << std::endl;

	delete a;
}
