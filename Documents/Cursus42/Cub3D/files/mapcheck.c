/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:47:33 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/27 14:40:02 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	checkcol(t_mother *s, int (*check)[s->map.maplinesize])
{
	int		i;

	i = s->map.mapstart;
	while (s->map.map[i] && i < (s->map.linenb - 1))
	{
		if (s->map.map[i][0] != '1' && check[i][1] == 1)
			ft_error("map open", s);
		i++;
	}
}

void	flood(int x, int y, t_mother *s, int (*check)[s->map.maplinesize])
{
	int		c;

	c = s->map.map[y][x];
	check[y][x] = 1;
	if (c == ' ' || ((c == '0' || c == '2') && x <= 0))
		ft_error("map open", s);
	else if ((c == '0' || c == '2') && x >= s->map.maplinesize - 1)
		ft_error("map open", s);
	else if (((c == '0' || c == '2') && (y >= (s->map.linenb - 1)
		|| y <= s->map.mapstart)))
		ft_error("map open", s);
	else if (c == 48 || c == 50)
	{
		if ((x + 1) < s->map.maplinesize && check[y][x + 1] == 0)
			flood((x + 1), y, s, check);
		if ((x - 1) >= 0 && check[y][x - 1] == 0)
			flood((x - 1), y, s, check);
		if ((y + 1) < (s->map.linenb) && check[y + 1][x] == 0)
			flood(x, (y + 1), s, check);
		if ((y - 1) >= s->map.mapstart && check[y - 1][x] == 0)
			flood(x, (y - 1), s, check);
	}
	checkcol(s, check);
}

void	floodinit(t_mother *s)
{
	int		i;
	int		j;
	int		check[s->map.linenb][s->map.maplinesize];

	i = 0;
	while (i < s->map.linenb)
	{
		j = 0;
		while (j < s->map.maplinesize)
		{
			check[i][j] = 0;
			j++;
		}
		i++;
	}
	flood((int)floor(s->ply.py), (int)floor(s->ply.px), s, check);
}
