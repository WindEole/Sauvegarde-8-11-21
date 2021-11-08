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