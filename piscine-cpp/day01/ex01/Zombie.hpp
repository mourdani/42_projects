/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 06:03:55 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/09 01:13:22 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


class Zombie
{
	private :
		// name of the zombie.	
		std::string _name;

	public :
		// Default Constructor.
		Zombie();
		// Constructor taking zombie name.
		Zombie(std::string name);

		// Function to announce the zombie.
		void announce(void);
}; 

// Functions asked to implement
Zombie* newZombie(std::string name);
void    randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);
