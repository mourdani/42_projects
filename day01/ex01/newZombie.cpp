/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 06:08:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/09 01:20:24 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a pointer to object zombie, names it and return it for later us
// STORED ON THE HEAP for later use (or use outside of the function block)
Zombie*	newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	if (!zombie)
		return NULL;

	return zombie;
}
