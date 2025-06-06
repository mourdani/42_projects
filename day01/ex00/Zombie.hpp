/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 06:03:55 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/09 02:51:56 by mourdani         ###   ########.fr       */
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
		// Constructor which will give the zombie the name inputed.
		Zombie(std::string name)
		{
			_name = name;
		}

		// Function to announce the zombie.
		void announce(void)
		{
			std::cout << _name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
		}

		~Zombie()
		{
			std::cout << _name <<" has been destroyed"<< std::endl;
		}
}; 

// Functions asked to implement
Zombie* newZombie(std::string name);
void    randomChump(std::string name);
