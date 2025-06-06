/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:48:09 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/10 15:10:22 by mourdani         ###   ########.fr       */
/*   Updated: 2022/09/29 01:57:38 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	// Phonebook is a class containing 8 contacts. phonebook[7]; 
	// command is the input command;
	Phonebook phonebook;
	std::string command;

	// !! Think about removing the static
	static int i = 0;
	while (std::cin)
	{
		// replace oldest contact with newest one
		if (i > 7) i %= 8;
		std::cout << BOLD_LINE << std::endl;
		std::cout << "Enter a command..." << std::endl;
		std::cin >> command;
		std::cout << BOLD_LINE << std::endl;

		// Execute function according to the inputed command
		if (command.compare("ADD") == 0)
			phonebook.contact[i++].add();

		else if (command.compare("SEARCH") == 0)
			phonebook.search();

		else if (command.compare("EXIT") == 0) return 0;

		else std::cout << "COMMAND UNKNOWN.\tAvailable commands : ADD, SEARCH, EXIT" << std::endl;
	}
	return 0;
}
