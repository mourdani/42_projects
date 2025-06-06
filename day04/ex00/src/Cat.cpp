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
}

Cat::Cat(const Cat & cpy) : Animal(cpy) {
    std::cout << "Cat copy constructor has been called\n";
    *this = cpy;
}

Cat &Cat::operator=(const Cat & cpy) {
    std::cout << "Assignation operator has been called\n";
    setType(cpy.getType());
    return *this;
}

Cat::~Cat() {
        std::cout << "Cat Destructor has been called\n";
}

void Cat::makeSound() const {
    std::cout << "Meow Meow Meow\n";
};