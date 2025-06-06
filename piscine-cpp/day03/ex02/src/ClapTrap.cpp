/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:13 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 09:01:18 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " Constructor has been called\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10),  _energy_pts(10), _attack_dmg(0) {
	std::cout << "ClapTrap " << this->_name << " Constructor called\n";
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad): _name(name), _hit_pts(hp),  _energy_pts(ep), _attack_dmg(ad) {
	std::cout << "ClapTrap " << this->_name << " Constructor called\n";
} 

ClapTrap::ClapTrap(const ClapTrap & cpy): _name(cpy._name), _hit_pts(cpy._hit_pts),  _energy_pts(cpy._energy_pts), _attack_dmg(cpy._attack_dmg) {}

ClapTrap &ClapTrap::operator=(const ClapTrap & cpy) {
	if (this != &cpy)
	{
		std::cout << "ClapTrap Copy Constructor called\n";
		this->_name = cpy._name;
		this->_hit_pts = cpy._hit_pts;
		this->_energy_pts = cpy._energy_pts;
		this->_attack_dmg = cpy._attack_dmg;
	}
	return (*this);
}
	
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " Deconstructor has been called\n";
}

void ClapTrap::attack(const std::string &target) {
	if (this->_hit_pts <= 0 || this->_energy_pts <= 0)
	{ std::cout << "Cannot attack right now\n"; return; }

	std::cout << "ClapTrap " << this->_name << " attacks "
	<< target << ", causing " << this->_attack_dmg << " points of damage!\n";

	this->_energy_pts--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hit_pts -= amount;

	std::cout << "ClapTrap " << this->_name << " lost " << amount << " Hit points \n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_pts <= 0 || this->_energy_pts <= 0)
	{ std::cout << "Cannot be repaired right now\n"; return; }

	std::cout << "ClapTrap " << this->_name << " got back " << amount << " Hit points , and lost 1 energy point for reparation\n";

	this->_hit_pts += amount;
	this->_energy_pts--;
}
