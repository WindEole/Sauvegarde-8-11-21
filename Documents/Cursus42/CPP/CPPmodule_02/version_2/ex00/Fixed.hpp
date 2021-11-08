#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	int _fixe;
	static const int _fra_bits;

};

#endif