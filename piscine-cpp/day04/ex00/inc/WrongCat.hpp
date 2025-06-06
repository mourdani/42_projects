/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:52:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:56:47 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public :
        WrongCat();
		WrongCat(const WrongCat & cpy);
		~WrongCat();
		
		WrongCat &operator=(const WrongCat & cpy);

        void makeSound() const;
};

#endif