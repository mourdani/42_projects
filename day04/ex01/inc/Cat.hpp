/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:52:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:56:47 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    private:
        Brain* _brain;
    public :
        Cat();
		Cat(const Cat & cpy);
		~Cat();
		
		Cat &operator=(const Cat & cpy);

        void makeSound() const;       
        Brain *getBrain(void) const;
};

#endif