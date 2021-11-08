/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:23:20 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 13:27:22 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	clean(int *nth_bit, int *index, int *tab)
{
	*nth_bit = 7;
	*index = 0;
	tab[COUNTER] = 31;
	tab[LEN] = 0;
	tab[FINISHED] = 0;
}
