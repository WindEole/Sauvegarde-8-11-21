/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3dutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:42:52 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/25 21:04:59 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	structinit(char *mapfile, int save)
{
	t_mother	s;
	t_map		map;
	t_window	win;
	t_player	ply;

	win.ptr = NULL;
	win.ptrmlx = NULL;
	win.y = 0;
	win.winwidth = 0;
	win.winheight = 0;
	win.title = "cub3d";
	map.save = save;
	ply.px = 1;
	ply.py = 1;
	s.map = map;
	s.ply = ply;
	s.win = win;
	structinitspr(&s, mapfile);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
