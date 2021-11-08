/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:17:44 by lchapren          #+#    #+#             */
/*   Updated: 2021/08/18 11:46:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << "--- Int ---" << std::endl;
	Array<int> intEmpty;
	Array<int> intArray(5);
	std::cout << "intEmpty: " << intEmpty << std::endl;
	std::cout << "intEmpty size: " << intEmpty.size() << std::endl;
	std::cout << "intArray: " << intArray << std::endl;
	std::cout << "intArray size: " << intArray.size() << std::endl;

	std::cout << std::endl;
	std::cout << "-> Out of Range (intEmpty)" << std::endl;
	try
	{
		std::cout << intEmpty[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-> Assignation" << std::endl;
	intArray[2] = 42;
	std::cout << "intArray: " << intArray << std::endl;
	intEmpty = intArray;
	std::cout << "intEmpty: " << intEmpty << std::endl;
	intArray[4] = 13;
	std::cout << "intArray: " << intArray << std::endl;
	std::cout << "intEmpty: " << intEmpty << std::endl;

	std::cout << std::endl;
	std::cout << "-> Copy" << std::endl;
	Array<int> intCopy(intArray);
	std::cout << "intArray: " << intArray << std::endl;
	std::cout << "intCopy: " << intCopy << std::endl;

	std::cout << std::endl;
	std::cout << "-> Out of Range (intArray)" << std::endl;
	try
	{
		std::cout << intArray[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << intArray[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	

	std::cout << std::endl << std::endl;
	std::cout << "--- Char ---" << std::endl;
	Array<char> charEmpty;
	Array<char> charArray(3);
	std::cout << "charEmpty: " << charEmpty << std::endl;
	std::cout << "charEmpty size: " << charEmpty.size() << std::endl;
	std::cout << "charArray: " << charArray << std::endl;
	std::cout << "charArray size: " << charArray.size() << std::endl;

	std::cout << std::endl;
	std::cout << "-> Out of Range (charEmpty)" << std::endl;
	try
	{
		std::cout << charEmpty[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-> Assignation" << std::endl;
	charArray[1] = 'r';
	std::cout << "charArray: " << charArray << std::endl;
	charEmpty = charArray;
	std::cout << "charEmpty: " << charEmpty << std::endl;
	charArray[2] = 'j';
	std::cout << "charArray: " << charArray << std::endl;
	std::cout << "charEmpty: " << charEmpty << std::endl;

	std::cout << std::endl;
	std::cout << "-> Copy" << std::endl;
	Array<char> charCopy(charArray);
	std::cout << "charArray: " << charArray << std::endl;
	std::cout << "charCopy: " << charCopy << std::endl;

	std::cout << std::endl;
	std::cout << "-> Out of Range (charArray)" << std::endl;
	try
	{
		std::cout << charArray[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << charArray[3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	

	std::cout << std::endl << std::endl;
	std::cout << "--- myClass ---" << std::endl;
	Array<myClass> myClassEmpty;
	Array<myClass> myClassArray(4);
	std::cout << "myClassEmpty: " << myClassEmpty << std::endl;
	std::cout << "myClassEmpty size: " << myClassEmpty.size() << std::endl;
	std::cout << "myClassArray: " << myClassArray << std::endl;
	std::cout << "myClassArray size: " << myClassArray.size() << std::endl;

	std::cout << std::endl;
	std::cout << "-> Out of Range (myClassEmpty)" << std::endl;
	try
	{
		std::cout << myClassEmpty[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-> Assignation" << std::endl;
	myClassArray[1] = 17;
	std::cout << "myClassArray: " << myClassArray << std::endl;
	myClassEmpty = myClassArray;
	std::cout << "myClassEmpty: " << myClassEmpty << std::endl;
	myClassArray[3] = 21;
	std::cout << "myClassArray: " << myClassArray << std::endl;
	std::cout << "myClassEmpty: " << myClassEmpty << std::endl;

	std::cout << std::endl;
	std::cout << "-> Copy" << std::endl;
	Array<myClass> myClassCopy(myClassArray);
	std::cout << "myClassArray: " << myClassArray << std::endl;
	std::cout << "myClassCopy: " << myClassCopy << std::endl;

	std::cout << std::endl;
	std::cout << "-> Out of Range (myClassArray)" << std::endl;
	try
	{
		std::cout << myClassArray[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << myClassArray[4] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}