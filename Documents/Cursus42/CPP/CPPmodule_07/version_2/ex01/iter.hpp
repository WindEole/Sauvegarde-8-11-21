/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:38:38 by lchapren          #+#    #+#             */
/*   Updated: 2021/08/17 11:58:49 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include "myClass.hpp"

template <typename T>
void iter(T* array, size_t length, void (*f)(T))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void printDouble(T value)
{
	std::cout << value  << value << std::endl;
}

#endif