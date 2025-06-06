/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:11 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 04:02:43 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main()
{
	ClapTrap robot("robot");
       robot.attack("lucky");	
       robot.takeDamage(5);	
       robot.beRepaired(5);	
       robot.takeDamage(3);	
       robot.takeDamage(3);	
       robot.takeDamage(3);	
       robot.takeDamage(3);	
       robot.beRepaired(5);	
       return 0;
}
