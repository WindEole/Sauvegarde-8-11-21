/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:50:04 by besellem          #+#    #+#             */
/*   Updated: 2021/08/08 21:25:20 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap(),
	FragTrap(),
	ScavTrap(),
	_name("UNKNOWN") {

	this->FragTrap::setHitPoints();
	this->ScavTrap::setEnergyPoints();
	this->FragTrap::setAttackDamage();
	this->ClapTrap::_name = _name + "_clap_name";

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	_name(name) {

	this->FragTrap::setHitPoints();
	this->ScavTrap::setEnergyPoints();
	this->FragTrap::setAttackDamage();

	std::cout << "DiamondTrap string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) :
	ClapTrap(ref._name + "_clap_name"),
	FragTrap(ref._name),
	ScavTrap(ref._name) {

	this->_name = ref._name;
	this->_hit_points = ref._hit_points;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}


void		DiamondTrap::attack(std::string const & target) {
	this->ScavTrap::attack(target);
}

DiamondTrap &		DiamondTrap::operator=(const DiamondTrap &ref) {
	
	if (this == &ref)
		return *this;
	
	this->_name = ref._name;
	this->ClapTrap::_name = ref._name + "_clap_name";
	this->_hit_points = ref._hit_points;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	return *this;
}

void			DiamondTrap::whoAmI(void) {
	std::cout << "My name is [" << this->_name \
			  << "] but my Claptrap name is [" << this->ClapTrap::_name \
			  << "]. I AM A DIAMOND TRAP ! : HP(" << this->_hit_points \
			  << ") EP(" << this->_energy_points \
			  << ") AD(" << this->_attack_damage << ")" \
			  << std::endl;
}
