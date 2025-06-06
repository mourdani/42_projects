/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:40:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 11:00:11 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() {}
FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30) {std::cout << "FragTrap " << this->_name << " Constructor called\n";}

FragTrap::FragTrap(const FragTrap & cpy): ClapTrap(cpy._name, 100, 100, 30) {std::cout << "FragTrap " << this->_name << " Copy Constructor called\n";}

FragTrap &FragTrap::operator=(const FragTrap & cpy) {
	if (this != &cpy) {
		std::cout << "FragTrap Copy Constructor called\n";
		this->_name = cpy._name;
		this->_hit_pts = cpy._hit_pts;
		this->_energy_pts = cpy._energy_pts;
		this->_attack_dmg = cpy._attack_dmg;
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " Deconstructor has been called\n";
}

void FragTrap::attack(const std::string &target) {
	if (this->_hit_pts <= 0 || this->_energy_pts <= 0)
	{ std::cout << "Cannot attack right now\n"; return; }

	std::cout << "FragTrap " << this->_name << " is Attacking "
	<< target << ", attack damage: " << this->_attack_dmg << "\n";

	this->_energy_pts--;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " wants High Fives.\n";
}
