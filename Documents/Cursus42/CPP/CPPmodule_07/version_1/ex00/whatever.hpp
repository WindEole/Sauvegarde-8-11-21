/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:32:23 by nboisde           #+#    #+#             */
/*   Updated: 2021/07/29 14:32:33 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
T const & min(T const & a, T const & b)
{
	return ((a < b) ? a : b);
}

template<typename T>
T const & max(T const & a, T const & b)
{
	return ((a > b) ? a : b);
}

template<typename T>
void swap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#endif
