/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:11 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 10:44:18 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main()
{
	ScavTrap guard("guard");
	ScavTrap bruh(guard);
	ScavTrap copsty("coptsy");

	guard.attack("lucky");	
	guard.takeDamage(9);	
	guard.beRepaired(5);	
	guard.guardGate();	

	copsty.guardGate();
	guard.takeDamage(200);	
	guard.beRepaired(5);	
	return 0;
}
