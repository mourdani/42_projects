/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:05:49 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/28 15:05:53 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Iter.hpp"

int main() {

	int tab[] = { 0, 1, 2, 3, 4 };
	Example tab2[5];
	float	tab3[5] = {12.3 , 11.2, 66.7, 45.5, 12.8};
	std::string tab4[5] = {"hey", "this", "is", "a", "test."};
	
	std::cout << "============ Int array ===========" << std::endl;
	try	{
		iter(tab, 5, print);
	}
	catch (const std::out_of_range& e) {
    	std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "============ Object array ===========" << std::endl;
	try	{
		iter(tab2, 5, print);
	}
	catch (const std::out_of_range& e) {
    	std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "============ float array ===========" << std::endl;
	try	{
		iter(tab3, 5, print);
	}
	catch (const std::out_of_range& e) {
    	std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "============ std::string array ===========" << std::endl;
	try	{
		iter(tab4, 5, print);
	}
	catch (const std::out_of_range& e) {
    	std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
