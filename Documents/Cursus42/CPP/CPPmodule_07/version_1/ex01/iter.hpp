/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:12:54 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/04 18:03:49 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T* array, int a, T(*f)(T))
{
	int i = 0;
	while (i < a)
	{
		array[i] = (*f)(array[i]);
		i++;
	}
}

template<typename T>
void	iter(T* array, int a, T(*f)(T*))
{
	int i = 0;
	while (i < a)
	{
		array[i] = (*f)(&(array[i]));
		i++;
	}
}

template<typename T>
void	iter(T* array, int a, void(*f)(T const &))
{
	int i = 0;
	while (i < a)
	{
		(*f)(array[i]);
		i++;
	}
}

#endif
