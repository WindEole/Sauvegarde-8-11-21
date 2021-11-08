/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:42:58 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 17:15:36 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		ft_screensize(t_mother *s, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 'R' && (line[i] < '0'
			|| line[i] > '9') && ft_space(line[i]) == 0)
			ft_error("resa", s);
		i++;
	}
	i = 0;
	s->win.winwidth = ft_atoi(line, &i);
	s->win.winheight = ft_atoi(line, &i);
	if (line[i] != '\0')
		if (line[i + 1] == '0' || ft_atoi(line, &i) > 0)
			ft_error("res", s);
	if (s->win.winwidth <= 5 || s->win.winheight <= 5)
		ft_error("res is low", s);
	if (s->win.winwidth >= 40000 || s->win.winheight >= 40000)
		write(1, "resolution too large reduced to sceen size\n", 42);
	if (s->win.winheight != 0 && s->win.winheight != 0)
		return (1);
	else
		ft_error("screensize", s);
	return (0);
}

void	ft_sprdraw(t_mother *s)
{
	s->spr.d = s->spr.k * 256 - s->win.winheight
		* 128 + s->spr.sprheight * 128;
	s->spr.texy = ((s->spr.d * s->spr.height)
		/ s->spr.sprheight) / 256;
	s->spr.color = getimgpixel(s->spr.texx, s->spr.texy,
		s->spr.adress, s->spr.bits);
	if (s->spr.color != 0)
		ftmlxpixel(s, s->spr.stripe, s->spr.k, s->spr.color);
	s->spr.k++;
}

void	ft_checkassign(t_mother *s)
{
	int		fd;

	fd = 0;
	ft_checkdirectory(fd, s->tex.s, s);
	if (!(fd = open(s->tex.s, O_RDONLY)) || fd == -1)
		ft_error("open", s);
	if (!(fd = open(s->tex.no, O_RDONLY)) || fd == -1)
		ft_error("open", s);
	if (!(fd = open(s->tex.ea, O_RDONLY)) || fd == -1)
		ft_error("open", s);
	if (!(fd = open(s->tex.so, O_RDONLY)) || fd == -1)
		ft_error("open", s);
}

void	ft_sprassign(t_mother *s)
{
	ft_checkassign(s);
	s->spr.stex = mlx_xpm_file_to_image(s->win.ptrmlx,
		s->tex.s, &s->spr.height, &s->spr.width);
	s->spr.adress = mlx_get_data_addr(s->spr.stex, &s->spr.bits,
		&s->spr.linesize, &s->spr.endian);
}

void	ft_parsespriteinit(t_mother *s)
{
	int		i;

	if (!(s->spr.sprdist = malloc(sizeof(double *) * s->spr.nbr + 1)))
		ft_error("malloc", s);
	if (!(s->spr.sprorder = malloc(sizeof(double *) * s->spr.nbr + 1)))
		ft_error("malloc", s);
	i = 0;
	while (i < s->spr.nbr)
	{
		s->spr.sprdist[i] = sqrt(pow((s->spr.x[i] - (int)s->ply.px), 2)
			+ pow((s->spr.y[i] - s->ply.py), 2));
		i++;
	}
}
