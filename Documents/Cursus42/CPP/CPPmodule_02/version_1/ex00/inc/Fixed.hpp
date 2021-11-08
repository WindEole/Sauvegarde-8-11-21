/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:35:30 by user42            #+#    #+#             */
/*   Updated: 2021/07/30 13:53:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int value;
	static const int  fractionalBits = 8;

public:
	Fixed( void );
	Fixed( const Fixed & fixed );

	~Fixed();

	Fixed & operator=(const Fixed &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif