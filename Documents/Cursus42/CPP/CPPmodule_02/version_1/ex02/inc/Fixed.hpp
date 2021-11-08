/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:35:30 by user42            #+#    #+#             */
/*   Updated: 2021/08/05 12:25:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int value;
	static const int fractionalBits = 8;

public:
	Fixed( void );
	Fixed( const Fixed & fixed );
	Fixed( const int n );
	Fixed( const float n );

	~Fixed();

	Fixed & operator=(const Fixed &rhs);
	bool	operator>(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	Fixed &	operator++(void);//pre-incrementation
	Fixed	operator++(int);//post-incrementation
	Fixed &	operator--(void);//pre-decrementation
	Fixed	operator--(int);//post-decrementation

	static Fixed &			min(Fixed &a, Fixed &b);
	static Fixed &			max(Fixed &a, Fixed &b);
	static const Fixed &	min(const Fixed &a, const Fixed &b);
	static const Fixed &	max(const Fixed &a, const Fixed &b);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream & operator<<(std::ostream & os, const Fixed &rhs);

#endif