/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:39:45 by nboisde           #+#    #+#             */
/*   Updated: 2021/07/29 14:40:34 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Subject tests:" << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << std::endl << "My tests:" << std::endl;

	int a = 0;
	int b = 21;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max: " << max<int>(a, b) << std::endl;
	std::cout << "min: " << min<int>(a, b) << std::endl;
	std::cout << "swap usage" << std::endl;
	swap<int>(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << "========================" << std::endl;

	float c = 42.0f;
	float d = 32.0f;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "max: "<< max<float>(c, d) << std::endl;
	std::cout << "min: "<< min<float>(c, d) << std::endl;
	std::cout << "swap usage" << std::endl;
	swap<float>(c, d);
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	std::cout << "========================" << std::endl;

	char e = 'e';
	char f = 'f';
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "max: " << max<char>(e, f) << std::endl;
	std::cout << "min: " << min<char>(e, f) << std::endl;
	std::cout << "swap usage" << std::endl;
	swap<char>(e, f);
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	return 0;
}
