/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 06:56:18 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/30 19:24:41 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>
#include <iostream>

class Weapon
{
	private :
		std::string _type;

	public :
		Weapon(){};
		Weapon(std::string type);
		const std::string& getType();
		void setType(std::string type);
};
#endif
