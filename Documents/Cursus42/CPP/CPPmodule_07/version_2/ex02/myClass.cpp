/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myClass.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:07:27 by lchapren          #+#    #+#             */
/*   Updated: 2021/08/18 11:35:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

myClass::myClass(void) : _n(0)
{
}

myClass::myClass(int n) : _n(n)
{
}

myClass::myClass(myClass const &rhs) : _n(rhs.getN())
{
}

myClass& myClass::operator=(myClass const &rhs)
{
	if (this != &rhs)
		_n = rhs.getN();
	return (*this);
}

myClass::~myClass(void)
{
}

bool myClass::operator<(myClass const &rhs) const
{
	return (_n < rhs.getN());
}

bool myClass::operator>(myClass const &rhs) const
{
	return (_n > rhs.getN());
}

int	myClass::getN(void) const
{
	return (_n); 
}

void myClass::setN(int n)
{
	_n = n;
}

std::ostream& operator<<(std::ostream& o, myClass const &rhs)
{
	o << rhs.getN();
	return (o);
}