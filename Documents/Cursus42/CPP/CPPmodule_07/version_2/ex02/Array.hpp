/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:56:55 by lchapren          #+#    #+#             */
/*   Updated: 2021/08/18 11:31:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include "myClass.hpp"

template <typename T>
class Array
{
	private:
		T* _value;
		unsigned int _size;

	public:
		Array(void) : _value(NULL), _size(0) {}

		Array(unsigned int n) : _size(n)
		{
			_value = new T[n];
			for (unsigned int i = 0; i < n; i++)
				_value[i] = 0;
		}
		
		Array(Array const &rhs)
		{
			_size = rhs.size();
			_value = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_value[i] = rhs[i];
		}

		Array& operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				if (_size)
					delete[] _value;
				_size = rhs.size();
				_value = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_value[i] = rhs[i];
			}
			return (*this);
		}
		
		T& operator[](int index) const
		{
			if (index < 0 || index >= static_cast<int>(_size))
				throw std::out_of_range("Index is Out of Range");
			else
				return (_value[index]);
		}

		~Array(void)
		{
			if (_size)
				delete[] _value;
		}

		unsigned int size(void) const
		{
			return (_size);
		}

		T* getValue(void) const
		{
			return (_value);
		}

		void setValue(T value)
		{
			_value = value;
		}
};

template <typename T>
std::ostream& operator<<(std::ostream& o, Array<T> const &rhs)
{
	o << "[ " ;
	for (unsigned int i = 0; i < rhs.size(); i++)
	{
		o << rhs[i];
		if (i != rhs.size() - 1)
			o << ", ";
	}
	o << " ]";
	return (o);
}

#endif