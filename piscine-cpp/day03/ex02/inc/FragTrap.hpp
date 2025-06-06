/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:08 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 10:55:18 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap {
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap & cpy);
		FragTrap &operator=(const FragTrap & cpy);
		~FragTrap();

		void attack(const std::string &target);
		void highFivesGuys();
};
