/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:33:08 by besellem          #+#    #+#             */
/*   Updated: 2021/08/05 11:10:07 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("UNKNOWN", 100, 100, 30) {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
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

void			FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap [" << this->getName() << "] says: Wanna high five guys ?!" << std::endl;
}
