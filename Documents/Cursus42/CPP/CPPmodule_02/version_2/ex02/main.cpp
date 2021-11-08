#include "Fixed.hpp"

int main(void) 
{
	Fixed a(2);
	Fixed b(4);
	Fixed c(8);
	Fixed d(16);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a + b =" << a + b << std::endl;
	std::cout << "b + c =" << b + c << std::endl;
	std::cout << "c + d =" << c + d << std::endl;

	std::cout << "b - a =" << b - a << std::endl;
	std::cout << "c - b =" << c - b << std::endl;

	std::cout << "a * b =" << a * b << std::endl;
	std::cout << "c * d =" << c * d << std::endl;

	std::cout << "d / b =" << d / b << std::endl;
	std::cout << "c / a =" << c / a << std::endl;
	
	std::cout << "a < b" << std::endl;
	if (a < b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;


	std::cout << "a > b" << std::endl;
	if (a > b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;


	std::cout << "a == b" << std::endl;
	if (a == b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	

	std::cout << "a <= b" << std::endl;
	if (a <= b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "a <= a" << std::endl;
	if (a <= a)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "a >= b" << std::endl;
	if (a >= b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "a != b" << std::endl;
	if (a != b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << "min(c, b) = " << Fixed::min( c, b ) << std::endl;
	std::cout << "max(c, b) = " << Fixed::max( c, b ) << std::endl;
	return 0;
}