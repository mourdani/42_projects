/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 06:16:19 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/08 23:32:37 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a zombie, and announces its name.
// STORED IN THE STACK as we dont need to use it later.
void	randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}
