/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:49:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:26 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor has been called\n";
    this->_brain = new Brain();
}

Cat::Cat(const Cat & cpy) : Animal(cpy) {
    std::cout << "Cat copy constructor has been called\n";
    *this = cpy;
}

Cat &Cat::operator=(const Cat & cpy) {
    std::cout << "Cat Assignation operator has been called\n";
    if (this != &cpy) {
        setType(cpy.getType());
	    this->_brain = new Brain (*cpy.getBrain());
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor has been called\n";
    delete this->_brain;

}

void Cat::makeSound() const {
    std::cout << "Meow Meow Meow\n";
};

Brain *Cat::getBrain() const {
    return this->_brain;
}