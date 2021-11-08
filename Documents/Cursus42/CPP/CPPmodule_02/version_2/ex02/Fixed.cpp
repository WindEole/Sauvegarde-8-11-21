#include "Fixed.hpp"

const int Fixed::_fra_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixe = 0;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixe = n << _fra_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixe = roundf(n *(1 << _fra_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Asignation operator called" << std::endl;
	if (this != &rhs)
		this->_fixe = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixe;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixe = raw;
	return ;
}

int Fixed::toInt(void) const
{
	return this->_fixe >> _fra_bits;
}

float Fixed::toFloat(void) const 
{
	return ((float)(this->_fixe) / (float)(1 << _fra_bits));
}

std::ostream &operator<<(std::ostream &out, Fixed const &n)
{
	out << n.toFloat();
	return (out);
}

bool Fixed::operator>(Fixed const & rhs)
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs)
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs)
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs)
{
	return (this->getRawBits() != rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs)
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs)
{
	return (this->getRawBits() <= rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const & rhs)
{
	return (Fixed((float)(this->getRawBits() + rhs.getRawBits()) / (float)(1 << _fra_bits)));
}

Fixed Fixed::operator-(Fixed const & rhs)
{
	return (Fixed((float)(this->getRawBits() - rhs.getRawBits()) / (float)(1 << _fra_bits)));
}

Fixed Fixed::operator*(Fixed const & rhs)
{
	return (Fixed((float)(this->getRawBits() * rhs.getRawBits()) / ((float)(1 << _fra_bits) * (float)(1 << _fra_bits))));
}

Fixed Fixed::operator/(Fixed const & rhs)
{
	return (Fixed((float)(this->getRawBits() / rhs.getRawBits())));
}

Fixed & Fixed::operator++()
{
	++this->_fixe;
	return (*this);
}

Fixed & Fixed::operator--()
{
	--this->_fixe;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_fixe;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fixe;
	return (tmp);
}

Fixed & Fixed::min(Fixed & qhs, Fixed & rhs)
{
	if (qhs.getRawBits() < rhs.getRawBits())
		return (qhs);
	else
		return (rhs);
}

Fixed & Fixed::max(Fixed & qhs, Fixed & rhs)
{
	if (qhs.getRawBits() > rhs.getRawBits())
		return (qhs);
	else
		return (rhs);
}

Fixed const & Fixed::min(Fixed const & qhs, Fixed const & rhs)
{
	if (qhs.getRawBits() < rhs.getRawBits())
		return (qhs);
	else
		return (rhs);
}

Fixed const & Fixed::max(Fixed const & qhs, Fixed const & rhs)
{
	if (qhs.getRawBits() > rhs.getRawBits())
		return (qhs);
	else
		return (rhs);
}