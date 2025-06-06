/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:46:28 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 17:20:19 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>


class WrongAnimal {
	protected :
		std::string _type;
	public :
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal & cpy);
		~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal & cpy);
		
		void makeSound() const;
		std::string getType(void) const;
		void setType(std::string const newtype);
};

#endif