/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:49:28 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 17:19:24 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
int main( void )
{
    const Animal* meta = new Animal("_Animal_");
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete i;
    std::cout << "==========================" << std::endl;
    delete j;
    std::cout << "==========================" << std::endl;
    delete meta;
    /* * * * * * * * * * * * * * * * * * * * * * */
    std::cout << "===========ex01===========" << std::endl;
    Animal * dog = new Dog();
    Animal * cat = new Cat();
    cat -> makeSound();
    dog -> makeSound();

    delete dog;
    delete cat;
    return 0;
}
/*
int main() {
  // Create an array of Animal objects and fill it with a mix of Dog and Cat objects
  Animal* animals[10];
  for (int i = 0; i < 5; i++) {
    animals[i] = new Dog();
  }
  for (int i = 5; i < 10; i++) {
    animals[i] = new Cat();
  }

  // Loop over the array and delete each Animal object
  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }

  return 0;
}*/