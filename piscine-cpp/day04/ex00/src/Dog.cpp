/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:49:27 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:28 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor has been called\n";
}

Dog::Dog(const Dog & cpy) : Animal(cpy) {
    std::cout << "Dog copy constructor has been called\n";
    *this = cpy;
}

Dog &Dog::operator=(const Dog & cpy) {
    std::cout << "Assignation operator has been called\n";
    setType(cpy.getType());
    return *this;
}

Dog::~Dog() {
        std::cout << "Dog Destructor has been called\n";
}

void Dog::makeSound() const {
    std::cout << "Waf waf waf, wafffffff\n";
}; 
