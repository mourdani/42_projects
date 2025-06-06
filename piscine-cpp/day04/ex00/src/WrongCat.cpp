/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:49:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:26 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"



WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor has been called\n";
}

WrongCat::WrongCat(const WrongCat & cpy) : WrongAnimal(cpy) {
    std::cout << "WrongCat copy constructor has been called\n";
    *this = cpy;
}

WrongCat &WrongCat::operator=(const WrongCat & cpy) {
    std::cout << "Assignation operator has been called\n";
    setType(cpy.getType());
    return *this;
}

WrongCat::~WrongCat() {
        std::cout << "WrongCat Destructor has been called\n";
}

void WrongCat::makeSound() const{
    std::cout << "Meow Meow Meow\n";
};