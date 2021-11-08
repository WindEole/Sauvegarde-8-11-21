/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:02:25 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 17:23:33 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(42.42f);
	Fixed const d(b);
	Fixed e(c);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl << std::endl;

	std::cout << c << " > " << b << " = " << (c > d) << std::endl;
	std::cout << c << " >= " << b << " = " << (c >= d) << std::endl;
	std::cout << c << " < " << b << " = " << (c < d) << std::endl;
	std::cout << c << " <= " << b << " = " << (c <= d) << std::endl;
	std::cout << c << " == " << b << " = " << (c == d) << std::endl;
	std::cout << c << " != " << b << " = " << (c != d) << std::endl << std::endl;

	std::cout << c << " + " << b << " = " << (c + d) << std::endl;
	std::cout << c << " - " << b << " = " << (c - d) << std::endl;
	std::cout << c << " * " << b << " = " << (c * d) << std::endl;
	std::cout << c << " / " << b << " = " << (c / d) << std::endl << std::endl;

	std::cout << "a = " << (a) << std::endl;
	std::cout << "++a = " << (++a) << std::endl;
	std::cout << "a = " << (a) << std::endl;
	std::cout << "a++ = " << (a++) << std::endl;
	std::cout << "a = " << (a) << std::endl;
	std::cout << "a-- = " << (a--) << std::endl;
	std::cout << "a = " << (a) << std::endl;
	std::cout << "--a = " << (--a) << std::endl;
	std::cout << "a = " << (a) << std::endl << std::endl;

	std::cout << "max("<< a << ", " << e << ") = " << Fixed::max(a, e) << std::endl;
	std::cout << "min("<< a << ", " << e << ") = " << Fixed::min(a, e) << std::endl;
	std::cout << "(const)max("<< b << ", " << c << ") = " << Fixed::max(b, c) << std::endl;
	std::cout << "(const)min("<< b << ", " << c << ") = " << Fixed::min(b, c) << std::endl << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl << std::endl;

	return 0;
}
