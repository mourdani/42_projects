/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:37:30 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/30 19:24:52 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP 
# define HUMANB_HPP 
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *_weapon;
		std::string _name;

	public:
		void attack(void);
		void setWeapon(Weapon &weapon);
		HumanB(std::string name);
		~HumanB(){};
};
#endif
