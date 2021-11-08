/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:06:17 by besellem          #+#    #+#             */
/*   Updated: 2021/08/05 11:08:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_name("UNKNOWN"),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0),
	_initial_hit_points(10),
	_initial_energy_points(10) {
	
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0),
	_initial_hit_points(10),
	_initial_energy_points(10) {

	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage) :
	_name(name),
	_hit_points(hit_points),
	_energy_points(energy_points),
	_attack_damage(attack_damage),
	_initial_hit_points(hit_points),
	_initial_energy_points(energy_points) {
	
	std::cout << "ClapTrap complete constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) {
	*this = ref;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}


ClapTrap &		ClapTrap::operator=(const ClapTrap &ref) {
	
	if (this == &ref)
		return *this;
	
	this->_name = ref._name;
	this->_hit_points = ref._hit_points;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	return *this;
}


std::string		ClapTrap::getName(void) const { return this->_name; }

void		ClapTrap::attack(std::string const & target) {
	std::cout << "[" << this->getName() \
			  << "] attacks [" << target \
			  << "], causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount) {

	if ((int)amount > this->_energy_points) {
		this->_hit_points -= ((int)amount - this->_energy_points);
		this->_energy_points = 0;
	} else {
		this->_energy_points -= amount;
	}
	
	if (this->_hit_points <= 0 && this->_energy_points <= 0) {
		std::cout << "[" << this->getName() \
				  << "] takes " << amount << " points of damage and it dies!" << std::endl;
	}
	else {
		std::cout << "[" << this->getName() \
				  << "] takes " << amount << " points of damage!" << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hit_points <= 0 && this->_energy_points <= 0) {
		
		std::cout << "[" << this->getName() \
				  << "] cannot be restored, it died tragically ..." << std::endl;
		return ;
	}

	if ((this->_hit_points + (int)amount) > this->_initial_hit_points) {
		this->_energy_points += this->_hit_points - this->_initial_hit_points + amount;
		this->_hit_points = this->_initial_hit_points;
	} else {
		this->_hit_points = amount;
	}

	if (this->_hit_points >= this->_initial_hit_points &&
		this->_energy_points >= this->_initial_energy_points) {

		std::cout << "[" << this->getName() \
				  << "] restored completely!" << std::endl;
	} else {

		std::cout << "[" << this->getName() \
				  << "] restored " << amount << " points!" << std::endl;
	}
}
