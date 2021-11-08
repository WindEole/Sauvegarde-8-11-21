/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:38:46 by besellem          #+#    #+#             */
/*   Updated: 2021/08/05 11:42:39 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &ref);
		virtual ~ScavTrap(void);
	
		ScavTrap &		operator=(const ScavTrap &ref);

		virtual void	setHitPoints(void);
		virtual void	setEnergyPoints(void);
		virtual void	setAttackDamage(void);

		virtual void	attack(std::string const & target);
		void			guardGate(void) const;
	
};

#endif
