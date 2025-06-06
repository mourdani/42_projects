/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:49:25 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:25 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor has been called\n";
}

Animal::Animal(std::string type): _type(type) {
    std::cout << "Animal parameterized constructor has been called\n";
}

Animal::Animal(const Animal & cpy) {
    std::cout << "Animal copy constructor has been called\n";
    *this = cpy;
}

Animal &Animal::operator=(const Animal & cpy) {
    std::cout << "Assignation operator has been called\n";
    setType(cpy.getType());
    return *this;
}

Animal::~Animal() {
        std::cout << "Animal Destructor has been called\n";
}

void Animal::makeSound() const {
    std::cout << "Inaudible " << this->_type << " animal voice\n";
}; 

std::string Animal::getType(void) const {
    return this->_type;
}

void Animal::setType(std::string const newtype) {
    this->_type = newtype;
}