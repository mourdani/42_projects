/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:00 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 16:56:53 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private :
		std::string ideas[100];
    public :
        Brain();
		Brain(const Brain & cpy);
		~Brain();
		
		Brain &operator=(const Brain & cpy);
};

#endif