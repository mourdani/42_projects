/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:00 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:56:53 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public :
        Dog();
		Dog(const Dog & cpy);
		~Dog();
		
		Dog &operator=(const Dog & cpy);

        virtual void makeSound() const;
};

#endif