#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);

	bool operator<(Fixed const & rhs);
	bool operator>(Fixed const & rhs);
	bool operator==(Fixed const & rhs);
	bool operator!=(Fixed const & rhs);
	bool operator<=(Fixed const & rhs);
	bool operator>=(Fixed const & rhs);

	Fixed operator+(Fixed const & rhs);
	Fixed operator-(Fixed const & rhs);
	Fixed operator*(Fixed const & rhs);
	Fixed operator/(Fixed const & rhs);

	Fixed & operator++();
	Fixed & operator--();

	Fixed  operator++(int);
	Fixed  operator--(int);

	static Fixed & min(Fixed & qhs, Fixed & rhs);
	static Fixed & max(Fixed & qhs, Fixed & rhs);

	static const Fixed & min(Fixed const & qhs, Fixed const & rhs);
	static const Fixed & max(Fixed const & qhs, Fixed const & rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

private:

	int _fixe;
	static const int _fra_bits;

};

std::ostream &operator<<(std::ostream &out, Fixed const &n);

#endif