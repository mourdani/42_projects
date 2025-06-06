/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:46:28 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 17:20:19 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>


class Animal {
	protected :
		std::string _type;
	public :
		Animal();
		Animal(std::string type);
		Animal(const Animal & cpy);
		~Animal();

		Animal &operator=(const Animal & cpy);
		
		virtual void makeSound() const;
		std::string getType(void) const;
		void setType(std::string const newtype);
};

#endif