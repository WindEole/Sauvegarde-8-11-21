/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:35:24 by lchapren          #+#    #+#             */
/*   Updated: 2021/08/21 14:50:33 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "awesome.hpp"

/*int main(void)
{
Awesome a(2), b(4);

swap(a, b);
std::cout << a << " " << b << std::endl;
std::cout << max(a, b) << std::endl;
std::cout << min(a, b) << std::endl;
return (0);
}*/
// pour compiler : clang++ main.cpp

int	main(void)
{
	// Values
	int intA = 42;
	int intB = -39;
	int intM = 21;
	int intN = 21;
	char charA = 'c';
	char charB = 'h';
	float floatA = 81.3f;
	float floatB = -2.6f;
	myClass myClassA(-51);
	myClass myClassB(6);
	std::string strA = "Bingo";
	std::string strB = "Bongo";
	
	std::cout << "--- Min() ---" << std::endl;
	std::cout << std::endl;

	std::cout << "-> int" << std::endl;
	std::cout << "intA: " << intA << ", intB: " << intB << std::endl;
	std::cout << "min is: " << ::min(intA, intB) << std::endl;
	std::cout << "&intM: " << &intM << ", &intN: " << &intN << std::endl;
	std::cout << "min is: " << &(::min(intM, intN)) << std::endl;
	std::cout << std::endl;

	std::cout << "-> char" << std::endl;
	std::cout << "charA: " << charA << ", charB: " << charB << std::endl;
	std::cout << "min is: " << ::min(charA, charB) << std::endl;
	std::cout << std::endl;

	std::cout << "-> float" << std::endl;
	std::cout << "floatA: " << floatA << ", floatB: " << floatB << std::endl;
	std::cout << "min is: " << ::min(floatA, floatB) << std::endl;
	std::cout << std::endl;

	std::cout << "-> myClass" << std::endl;
	std::cout << "myClassA: " << myClassA.getN() << ", myClassB: " << myClassB.getN() << std::endl;
	std::cout << "min is: " << ::min(myClassA, myClassB).getN() << std::endl;
	std::cout << std::endl;



	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "--- Max() ---" << std::endl;
	std::cout << std::endl;

	std::cout << "-> int" << std::endl;
	std::cout << "intA: " << intA << ", intB: " << intB << std::endl;
	std::cout << "max is: " << ::max(intA, intB) << std::endl;
	std::cout << "&intM: " << &intM << ", &intN: " << &intN << std::endl;
	std::cout << "max is: " << &(::max(intM, intN)) << std::endl;
	std::cout << std::endl;

	std::cout << "-> char" << std::endl;
	std::cout << "charA: " << charA << ", charB: " << charB << std::endl;
	std::cout << "max is: " << ::max(charA, charB) << std::endl;
	std::cout << std::endl;

	std::cout << "-> float" << std::endl;
	std::cout << "floatA: " << floatA << ", floatA: " << floatB << std::endl;
	std::cout << "max is: " << ::max(floatA, floatB) << std::endl;
	std::cout << std::endl;

	std::cout << "-> myClass" << std::endl;
	std::cout << "myClassA: " << myClassA.getN() << ", myClassB: " << myClassB.getN() << std::endl;
	std::cout << "max is: " << ::max(myClassA, myClassB).getN() << std::endl;
	std::cout << std::endl;



	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "--- Swap() ---" << std::endl;
	std::cout << std::endl;

	std::cout << "-> int" << std::endl;
	std::cout << "intA: " << intA << ", intB: " << intB << std::endl;
	std::cout << "Swaping" << std::endl;
	::swap(intA, intB);
	std::cout << "intA: " << intA << ", intB: " << intB << std::endl;
	std::cout << std::endl;

	std::cout << "-> char" << std::endl;
	std::cout << "charA: " << charA << ", charB: " << charB << std::endl;
	std::cout << "Swaping" << std::endl;
	::swap(charA, charB);
	std::cout << "charA: " << charA << ", charB: " << charB << std::endl;
	std::cout << std::endl;

	std::cout << "-> float" << std::endl;
	std::cout << "floatA: " << floatA << ", floatA: " << floatB << std::endl;
	std::cout << "Swaping" << std::endl;
	::swap(floatA, floatB);
	std::cout << "floatA: " << floatA << ", floatB: " << floatB << std::endl;
	std::cout << std::endl;

	std::cout << "-> myClass" << std::endl;
	std::cout << "myClassA: " << myClassA.getN() << ", myClassB: " << myClassB.getN() << std::endl;
	std::cout << "Swaping" << std::endl;
	::swap(myClassA, myClassB);
	std::cout << "myClassA: " << myClassA.getN() << ", myClassB: " << myClassB.getN() << std::endl;
	std::cout << std::endl;

	std::cout << "-> string" << std::endl;
	std::cout << "strA: " << strA << ", strB: " << strB << std::endl;
	std::cout << "Swaping" << std::endl;
	::swap(strA, strB);
	std::cout << "strA: " << strA << ", strB: " << strB << std::endl;
}

