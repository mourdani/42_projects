/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:49:25 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:25 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor has been called\n";
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
    std::cout << "WrongAnimal parameterized constructor has been called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal & cpy) {
    std::cout << "WrongAnimal copy constructor has been called\n";
    *this = cpy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal & cpy) {
    std::cout << "Assignation operator has been called\n";
    setType(cpy.getType());
    return *this;
}

WrongAnimal::~WrongAnimal() {
        std::cout << "WrongAnimal Destructor has been called\n";
}

void WrongAnimal::makeSound() const{
    std::cout << "Inaudible " << this->_type << " animal voice\n";
}; 

std::string WrongAnimal::getType(void) const {
    return this->_type;
}

void WrongAnimal::setType(std::string const newtype) {
    this->_type = newtype;
}