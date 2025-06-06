/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:49:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:26 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor has been called\n";
}

Brain::Brain(const Brain & cpy) {
    std::cout << "Brain copy constructor has been called\n";
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = cpy.ideas[i];
    }
}

Brain &Brain::operator=(const Brain & cpy) {
    std::cout << "Brain Assignation operator has been called\n";
    if (this != &cpy) {
      for (int i = 0; i < 100; i++) {
        this->ideas[i] = cpy.ideas[i];
      }
    }
    return *this;
}

Brain::~Brain() {
        std::cout << "Brain Destructor has been called\n";
}