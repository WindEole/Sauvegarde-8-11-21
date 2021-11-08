/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:44:29 by user42            #+#    #+#             */
/*   Updated: 2021/08/04 12:33:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <tgmath.h>

// Construtors/Destructors-----------------------------------------------------

Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & fixed)
{
	std::cout << "Copy constructor called" << std::endl;

	this->value = fixed.getRawBits();
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;

	this->value = n * (1 << this->fractionalBits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;

	this->value = roundf(n * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Operator overload-----------------------------------------------------------

Fixed & Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	this->value = rhs.getRawBits();
	return (*this);
}

// Getters/setters-------------------------------------------------------------

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

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

// Ostream overload------------------------------------------------------------

std::ostream & operator<<(std::ostream & os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}