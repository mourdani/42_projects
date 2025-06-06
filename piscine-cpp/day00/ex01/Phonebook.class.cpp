/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:48:12 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/29 02:04:00 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	Phonebook::search(void)
{
	int i = -1;

	// Search table output
	std::cout << SLIM_LINE << std::endl;
	std::cout << "|" << "  Index   "
	<< "|" << "First name" << "|" << " Last name"
	<< "|" << " Nickname " << "|" << std::endl;
	std::cout << COLUMNS << std::endl;
	while (contact[++i].set == 1 && i < 8)
	{
		std::cout	<< "|" << "         " << contact[i].index
		<< "|" << ptrunk(contact[i].getFirst())
		<< "|" <<  ptrunk(contact[i].getLast())
		<< "|" << ptrunk(contact[i].getNick())
		<< "|" << std::endl;
	}
	std::cout << COLUMNS << std::endl << std::endl;

	// Index display output
	std::cout << "Enter the index of the to display :";
	int index = 0;
	std::cin >> index; 
	if (index <= 0 || index > 8 || contact[index -1].set != 1 || !index) // check if index is not existent 
	{
		std::cout << "index non existent" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cout << SLIM_LINE << std::endl;
		std::cout << "First name: ";
		std::cout << "\t\t\t\t" << contact[index - 1].getFirst() << std::endl;
		std::cout <<  "Last name: ";
		std::cout << "\t\t\t\t" << contact[index - 1].getLast() << std::endl;
		std::cout <<  "Nickname: ";
		std::cout << "\t\t\t\t" <<  contact[index - 1].getNick() << std::endl;
		std::cout <<  "Darkest secret: ";
		std::cout << "\t\t\t" <<  contact[index - 1].getSecret() << std::endl;
		std::cout <<  "Number: ";
		std::cout << "\t\t\t\t" <<  contact[index - 1].getNumber() << std::endl;
	}
	return (0);
}
