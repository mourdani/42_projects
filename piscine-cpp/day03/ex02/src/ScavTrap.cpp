/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:40:26 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 10:42:34 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() {}
ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20) {std::cout << "ScavTrap " << this->_name << " Constructor called\n";}

ScavTrap::ScavTrap(const ScavTrap & cpy): ClapTrap(cpy._name, 100, 50, 20) {std::cout << "ScavTrap " << this->_name << " Copy Constructor called\n";}

ScavTrap &ScavTrap::operator=(const ScavTrap & cpy) {
	if (this != &cpy) {
		std::cout << "ScavTrap Copy Constructor called\n";
		this->_name = cpy._name;
		this->_hit_pts = cpy._hit_pts;
		this->_energy_pts = cpy._energy_pts;
		this->_attack_dmg = cpy._attack_dmg;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " Deconstructor has been called\n";
}

void ScavTrap::attack(const std::string &target) {
	if (this->_hit_pts <= 0 || this->_energy_pts <= 0)
	{ std::cout << "Cannot attack right now\n"; return; }

	std::cout << "ClapTrap " << this->_name << " attacks violently"
	<< target << ", causing " << this->_attack_dmg << " points of damage! its target is suffering huge injuries\n";

	this->_energy_pts--;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " entered guard mode\n";
}
