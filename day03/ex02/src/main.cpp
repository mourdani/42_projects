/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:11 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 10:59:23 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main()
{
	FragTrap guard("guard");
	FragTrap bruh(guard);
	FragTrap copsty("coptsy");

	guard.attack("lucky");	
	guard.takeDamage(9);	
	guard.highFivesGuys();	
	guard.beRepaired(5);	

	copsty.highFivesGuys();
	return 0;
}
