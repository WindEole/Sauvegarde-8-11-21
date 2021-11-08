/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:06:20 by besellem          #+#    #+#             */
/*   Updated: 2021/08/05 11:09:36 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage);
		ClapTrap(const ClapTrap &ref);
		~ClapTrap(void);

		ClapTrap &		operator=(const ClapTrap &ref);

		std::string		getName(void) const;

		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
	
	protected:
		std::string		_name;
		int				_hit_points;
		int				_energy_points;
		int				_attack_damage;
	
	private:
		int				_initial_hit_points;
		int				_initial_energy_points;
	
};

#endif
