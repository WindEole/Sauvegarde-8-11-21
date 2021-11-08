/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myClass.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:59:43 by lchapren          #+#    #+#             */
/*   Updated: 2021/08/17 12:06:21 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCLASS_HPP
# define MYCLASS_HPP

class myClass
{
	private:
		int	_n;

	public:
		myClass(void);
		myClass(int n);
		myClass(myClass const &rhs);
		myClass& operator=(myClass const &rhs);
		~myClass(void);

		bool operator<(myClass const &rhs) const;
		bool operator>(myClass const &rhs) const;

		int	getN(void) const;
		void setN(int n);
};

std::ostream& operator<<(std::ostream& o, myClass const &rhs);

#endif