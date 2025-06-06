/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:24:05 by mourdani          #+#    #+#             */
/*   Updated: 2022/10/28 01:56:47 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sed.hpp"

std::string	sed(std::string buffer, std::string str1,  std::string str2){

	int i = 0; // index
	while (1) {
		// get index of found str1, break otherwise
		if ((i = buffer.find(str1)) == -1) break;
		// Erase occurence of str1 at index
		buffer.erase(i, str1.length());
		// Insert str2 at index 
		buffer.insert(i, str2);
	}
	return buffer;
}

int	main(int ac, char **av) {

	if (ac != 4)
	{
		std::cout << "[USAGE] ./sed filename string_original string_replace";
		return 1;
	}
	
	// Intitialise variables
	std::string filename(av[1]);
	std::string str1(av[2]);
	std::string str2(av[3]);
	std::string buffer;

	// create file object for original file
	std::ifstream ofile(av[1]);

	// check for errors
	if (str1.empty() || ofile.fail()) return 1;

	// Loop to store content of file object to buffer
	while (ofile.good()) buffer += ofile.get();

	// Create cfile by appending ".replace" to ofile
	std::ofstream cfile((filename.append(".replace")).c_str(), std::ofstream::out);

	// Replace and append to cfile
	cfile << sed(buffer, av[2], av[3]);

	std::cout << "Replacement done succesfully!\n";

	// close files
	ofile.close();
	cfile.close();

	return 0;
}
