/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:38:42 by besellem          #+#    #+#             */
/*   Updated: 2021/08/05 11:47:14 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref) {
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}


ScavTrap &		ScavTrap::operator=(const ScavTrap &ref) {
	
	if (this == &ref)
		return *this;
	
	this->_name = ref._name;
	this->_hit_points = ref._hit_points;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	return *this;
}


void		ScavTrap::setHitPoints(void)    { this->_hit_points = 100; }
void		ScavTrap::setEnergyPoints(void) { this->_energy_points = 50; }
void		ScavTrap::setAttackDamage(void) { this->_attack_damage = 20; }

void		ScavTrap::attack(std::string const & target) {
	std::cout << "ScavTrap [" << this->_name \
			  << "] attacks [" << target \
			  << "], causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void			ScavTrap::guardGate(void) const {

	if (this->_energy_points <= 0 && this->_hit_points <= 0) {
		std::cout << "ScavTrap [" << this->getName() << "] cannot be a guardian anymore, it died tragically ..." << std::endl;
	} else {
		std::cout << "ScavTrap [" << this->getName() << "] is now a guardian of the gate" << std::endl;
	}
}
