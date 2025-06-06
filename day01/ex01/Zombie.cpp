/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:32:34 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/09 01:13:54 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	//std::cout << "Constructor has been called" << std::endl;
}

// Function to name the zombie
Zombie::Zombie(std::string name): _name(name) {}

// Zombie announcement.
void Zombie::announce(void)
{
	std::cout << _name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}
