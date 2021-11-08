/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:14:58 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/05 09:55:34 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template<typename T>
class Array
{
	public:
		Array<T>(void) : _array(new T[1]), _len(1) {_array[0] = 0;}
		~Array<T>(){
			delete []_array;
		}
		Array<T>(unsigned int len){
			if (static_cast<int>(len) <= 0)
				throw Array<T>::ArrayTooBig();
			else
			{
				_array = new T[len];
				_len = len;
			}
			//for (unsigned int i = 0; i < len; i++)
			//	_array[i] = 0;
		}
		Array<T>(Array<T> const & src){
			_array = new T[src.size()];
			for (unsigned int i = 0; i < src.size(); i++)
				_array[i] = src._array[i];
			_len = src.size();
		}
		Array<T> & operator=(Array<T> const & rhs){
			if (_array)
				delete [] _array;
			this->_array = new T[rhs.size()];
			for (unsigned int i = 0; i < rhs.size(); i++)
				_array[i] = (rhs.getArray())[i];
			return *this;
		}

		class BadIndex: public std::exception
		{
			public:
				BadIndex(void){}
				virtual ~BadIndex(void) throw(){}
				virtual const char * what() const throw(){return "Bad index.";}
		};
		class ArrayTooBig: public std::exception
		{
			public:
				ArrayTooBig(void){}
				virtual ~ArrayTooBig(void) throw(){}
				virtual const char * what() const throw(){return "Exploding Stack or array size 0";}
		};
		T & operator[](unsigned int idx)
		{
			if (idx >= this->size() || idx < 0)
				throw Array<T>::BadIndex();
			else
				return _array[idx];
		}

		T operator[](unsigned int idx) const
		{
			if (idx >= this->size || idx < 0)
				throw Array<T>::BadIndex();
			else
				return _array[idx];
		}

		unsigned int size(void) const{return _len;}
		T* getArray(void) const{return _array;}

	private:
		T* _array;
		unsigned int _len;
};

template<typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const rhs)
{
	for (unsigned int i = 0; i < rhs.size() - 1; i++)
		o << rhs.getArray()[i] << ", ";
	o << rhs.getArray()[rhs.size() - 1];
	return o;
}

#endif
