/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:44:29 by user42            #+#    #+#             */
/*   Updated: 2021/08/05 12:27:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <tgmath.h>

// Construtors/Destructors-----------------------------------------------------

Fixed::Fixed(void): value(0)
{
}

Fixed::Fixed(const Fixed & fixed)
{
	this->value = fixed.getRawBits();
}

Fixed::Fixed(const int n)
{
	this->value = n * (1 << this->fractionalBits);
}

Fixed::Fixed(const float n)
{
	this->value = roundf(n * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
}

// Operators overload----------------------------------------------------------

Fixed &	Fixed::operator=(const Fixed &rhs)
{
	this->value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->value > rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->value >= rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->value < rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->value <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->value == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->value != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed results;
	results.setRawBits(this->value + rhs.getRawBits());
	return (results);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed results;
	results.setRawBits(this->value - rhs.getRawBits());
	return (results);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed results;
	results.setRawBits(this->value * rhs.getRawBits() / (1 << this->fractionalBits));
	return (results);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed results;
	results.setRawBits((float)this->value / (float)rhs.getRawBits() * (float)(1 << this->fractionalBits));
	return (results);
}

Fixed & Fixed::operator++()
{
	++this->value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->value;
	return (tmp);
}

Fixed & Fixed::operator--()
{
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->value;
	return (tmp);
}

// Getters/setters-------------------------------------------------------------

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return(this->value / (1 << this->fractionalBits));
}

float Fixed::toFloat(void) const
{
	return((float)this->value / (float)(1 << this->fractionalBits));
}

// static function-------------------------------------------------------------

Fixed &	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

// Ostream overload------------------------------------------------------------

std::ostream & operator<<(std::ostream & os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}