/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:06:22 by besellem          #+#    #+#             */
/*   Updated: 2021/08/05 11:49:25 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
	
	DiamondTrap	serge("serge");
	DiamondTrap	serge_cpy;

	serge_cpy.whoAmI();
	serge_cpy = DiamondTrap("new");
	serge_cpy.whoAmI();

	serge.whoAmI();
	serge.highFivesGuys();
	serge.guardGate();
	serge.takeDamage(100);
	serge.attack("bosby");
	serge.takeDamage(50);
	serge.beRepaired(0);

	return 0;
}
