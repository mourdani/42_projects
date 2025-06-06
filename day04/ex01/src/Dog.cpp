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
    this->_brain = new Brain();
}

Dog::Dog(const Dog & cpy) : Animal(cpy) {
    std::cout << "Dog copy constructor has been called\n";
    *this = cpy;
}

Dog &Dog::operator=(const Dog & cpy){
    std::cout << "Dog Assignation operator has been called\n";
    if (this != &cpy) {
        setType(cpy.getType());
	    this->_brain = new Brain (*cpy.getBrain());
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor has been called\n";
    delete this->_brain;
}

void Dog::makeSound() const {
    std::cout << "Waf waf waf, wafffffff\n";
}; 

Brain *Dog::getBrain() const {
    return this->_brain;
}