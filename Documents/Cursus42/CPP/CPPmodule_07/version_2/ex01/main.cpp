/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:37:57 by lchapren          #+#    #+#             */
/*   Updated: 2021/08/17 12:11:28 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void diffTo42(int value)
{
	std::cout << 42 - value << std::endl;
}

void addSuffixe(std::string s)
{
	std::cout << s + " am I right?" << std::endl;
}

void printSquare(myClass c)
{
	std::cout << c.getN() * c.getN() << std::endl;
}

int main(void)
{
	std::cout << "--- Int array ---" << std::endl;
	size_t intLength = 3;
	int *intArray = new int[intLength];
	
	// Set int array at 0
	for (size_t i = 0; i < intLength; i++)
		intArray[i] = 0;
	
	::iter(intArray, intLength, diffTo42);
	std::cout << std::endl;
	::iter(intArray, intLength, printDouble);
	std::cout << std::endl;


	std::cout << "--- String array ---" << std::endl;
	size_t strLength = 26;
	std::string* strArray = new std::string[strLength];

	// Set string array as alphabet
	for (size_t i = 0; i < strLength; i++)
		strArray[i] = 65 + i;

	::iter(strArray, strLength, addSuffixe);
	std::cout << std::endl;

	::iter(strArray, strLength, printDouble);
	std::cout << std::endl;


	std::cout << "--- Class array ---" << std::endl;
	size_t classLength = 5;
	myClass* classArray = new myClass[classLength];
	
	// Set class array at 0
	for (size_t i = 0; i < classLength; i++)
		classArray[i].setN(i);
	
	::iter(classArray, classLength, printSquare);
	std::cout << std::endl;
	::iter(classArray, classLength, printDouble);

	delete[] intArray;
	delete[] strArray;
	delete[] classArray;
}