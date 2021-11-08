/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:33:08 by besellem          #+#    #+#             */
/*   Updated: 2021/08/05 11:47:37 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref) {
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}


FragTrap &		FragTrap::operator=(const FragTrap &ref) {
	
	if (this == &ref)
		return *this;
	
	this->_name = ref._name;
	this->_hit_points = ref._hit_points;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	return *this;
}


void		FragTrap::setHitPoints(void)    { this->_hit_points = 100; }
void		FragTrap::setEnergyPoints(void) { this->_energy_points = 100; }
void		FragTrap::setAttackDamage(void) { this->_attack_damage = 30; }

void		FragTrap::attack(std::string const & target) {
	std::cout << "FragTrap [" << this->_name \
			  << "] attacks [" << target \
			  << "], causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void			FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap [" << this->getName() << "] says: Wanna high five guys ?!" << std::endl;
}
