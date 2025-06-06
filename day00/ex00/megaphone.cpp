/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:03:56 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/24 19:21:15 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>


int main(int ac, char **av)
{
	int i = 0;

	if (ac > 1)
	{
		std::string str = av[1];
		if (str.empty())
		{
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;;
			return 0;
		}
	}
	
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;;
		return 0;
	}
		
	while (av[++i])
	{
		std::string str = av[i];
		std::use_facet<std::ctype<char> >(std::locale()).toupper(&str[0], &str[0] + str.size());
		if (av[i + 1]) 
			std::cout << str;
		else
			std::cout << str << std::endl;
	}
	return 0;
}
