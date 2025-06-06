/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:38:18 by mourdani          #+#    #+#             */
/*   Updated: 2022/10/28 00:43:46 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl(){
	std::cout << "constructor called\n";
}

Harl::~Harl(){
	std::cout << "distructor called\n";
}
  

void Harl::_debug( void ){
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese" 
		"triple-pickle-special-ketchup burger. I really do !\n";
}

void Harl::_info( void ){
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money."
		"You didn’t put enough bacon in my burger ! If you did, "
		"I wouldn’t be asking for more !\n";
}

void Harl::_warning( void ){
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free."
		"I’ve been coming for years whereas you started working here"
		"since last month.\n";
}

void Harl::_error( void ){
	std::cout << "[ERROR] This is unacceptable ! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level ){
	std::string complaint[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*display_function[4])(void) =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error,
	};
	for (int i = 0; i < 4; i++)
		if (level.compare(complaint[i]) == 0) (this->*display_function[i])();

}
