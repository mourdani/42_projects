/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:25:22 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/08 23:35:32 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *bruh = newZombie("Mr. Zombie");
	bruh->announce();

	randomChump("A random zombie");

	
	delete bruh;
	return 0;
}
