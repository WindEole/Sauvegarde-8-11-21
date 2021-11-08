/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:06:22 by besellem          #+#    #+#             */
/*   Updated: 2021/08/03 11:56:14 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	
	ClapTrap	unknown;
	ClapTrap	franck("Franck");
	ClapTrap	eddie("Eddie");

	franck.attack(unknown.getName());
	franck.attack(eddie.getName());
	franck.takeDamage(10);
	franck.beRepaired(10);
	franck.takeDamage(20);
	franck.beRepaired(10);

	return 0;
}
