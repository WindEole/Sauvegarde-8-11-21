/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:23:07 by nboisde           #+#    #+#             */
/*   Updated: 2021/07/29 15:23:09 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

std::string lol(std::string lol)
{
	static_cast<void>(lol);
	return ("lol");
}

int plus_42(int i)
{
	return (i + 42);
}

int main(void)
{
	std::string tab[3] = {"Nico", "Luke", "Nastasia"};
	int length = 3;

	for (int i = 0; i < length; i++)
	{
		std::cout << tab[i];
		if (i == length - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
	iter<std::string>(tab, length, &lol);
	for (int i = 0; i < length; i++)
	{
		std::cout << tab[i];
		if (i == length - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	std::cout << "=============" << std::endl;

	int tab2[5] = {0, 1, 2, 3, 4};
	int len = 5;
	for (int i = 0; i < len; i++)
	{
		std::cout << tab2[i];
		if (i == len - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
	iter<int>(tab2, len, &plus_42);
	for (int i = 0; i < len; i++)
	{
		std::cout << tab2[i];
		if (i == len - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
}
