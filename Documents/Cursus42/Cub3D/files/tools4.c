/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:18:41 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 18:15:37 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_missing(t_mother *s)
{
	if (s->tex.no == NULL || s->tex.so == NULL || s->tex.ea == NULL ||
		s->tex.we == NULL || s->tex.s == NULL || s->tex.c == 0 ||
			s->tex.f == 0 || s->win.winheight == 0 || s->win.winwidth == 0)
		ft_error("missing", s);
	if (s->ply.px == 1 || s->ply.py == 1)
		ft_error("no player", s);
}

void	ft_echap(t_mother *s)
{
	if (s->spr.distbuffer)
		free(s->spr.distbuffer);
	s->spr.distbuffer = NULL;
	if (s->tex.ea)
		free(s->tex.ea);
	if (s->tex.we)
		free(s->tex.we);
	if (s->tex.s)
		free(s->tex.s);
	if (s->tex.so)
		free(s->tex.so);
	if (s->tex.no)
		free(s->tex.no);
	if (s->map.map)
		free(s->map.map);
	s->map.map = NULL;
	s->tex.ea = NULL;
	s->tex.so = NULL;
	s->tex.s = NULL;
	s->tex.we = NULL;
	s->tex.so = NULL;
}

void	ft_bye(t_mother *s)
{
	if (s->tex.ptr)
		mlx_destroy_image(s->win.ptrmlx, s->tex.ptr);
	s->tex.ptr = NULL;
	if (s->spr.stex)
		mlx_destroy_image(s->win.ptrmlx, s->spr.stex);
	s->spr.stex = NULL;
	if (s->win.ptr)
		mlx_destroy_window(s->win.ptrmlx, s->win.ptr);
	s->win.ptr = NULL;
	if (s->win.ptrmlx)
		mlx_destroy_display(s->win.ptrmlx);
	free(s->win.ptrmlx);
	s->win.ptrmlx = NULL;
}

void	plyparse(t_mother *s, int i, int j)
{
	s->map.map[i][j] = '2';
	s->spr.y[s->spr.nbr] = j;
	s->spr.x[s->spr.nbr] = i;
	s->spr.nbr++;
}

void	ft_mapimalloc(t_mother *s, int i, char *line)
{
	s->map.map[i] = NULL;
	if (i >= s->map.mapstart &&
		!(s->map.map[i] = malloc(sizeof(char *) * ft_strlen(line) + 1)))
		ft_error("malloc", s);
	ft_mapfill(s, line, i);
}
