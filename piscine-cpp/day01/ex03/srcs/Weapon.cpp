/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 06:56:18 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/30 21:00:31 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

const std::string &Weapon::getType()
{
	std::string &type = _type;
	return type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
