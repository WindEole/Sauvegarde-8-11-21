/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:06:22 by besellem          #+#    #+#             */
/*   Updated: 2021/08/03 16:39:05 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void) {
	
	ScavTrap	scav("Scav");
	ClapTrap	franck("Franck");
	FragTrap	frog("Frog");

	franck.attack("NO_ID");
	franck.takeDamage(10);
	franck.beRepaired(100);
	franck.takeDamage(100);
	franck.takeDamage(10);
	franck.beRepaired(10);
	scav.attack("NO_ID");
	scav.guardGate();
	scav.takeDamage(100);
	scav.guardGate();
	scav.beRepaired(50);
	scav.takeDamage(100);
	scav.guardGate();
	frog.highFivesGuys();
	frog.takeDamage(100);
	frog.takeDamage(100);

	return 0;
}
