/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:15:05 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/04 16:04:39 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <list>

int main(void)
{
	Array<float> f1(5);
	f1[0] = 42.0f;
	f1[1] = 24.0f;
	f1[2] = 12.3333f;
	f1[3] = INFINITY;
	f1[4] = 33.8f;

	for (unsigned int i = 0; i < f1.size(); i++)
		std::cout << f1[i] << std::endl;
	try
	{
		f1[f1.size()];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "//-----------------------//" << std::endl;
	Array<std::string> stab(2);
	stab[0] = "Hello, \0";
	stab[1] = "defender\0";

	for (unsigned int i = 0; i < stab.size(); i++)
		std::cout << stab[i] << std::endl;

	Array<std::string> cpy(stab);
	for (unsigned int i = 0; i < stab.size(); i++)
		std::cout << stab[i] << std::endl;
	
	std::cout << "//-----------------------//" << std::endl;
	Array<bool> b(2);
	b[0] = true;
	b[1] = false;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	std::cout << b << std::endl;

	std::cout << "//-----------------------//" << std::endl;
	Array<int> i;
	std::cout << i << std::endl;
	std::cout << "//-----------------------//" << std::endl;
	try
	{
		Array<int> j(0);
		std::cout << j << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Array<int> j(-1);
		std::cout << j << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
