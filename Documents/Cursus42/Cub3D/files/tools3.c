/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:50:51 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 17:17:17 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_color(t_mother *s, char *line, char c)
{
	int		i;
	int		r;
	int		g;
	int		b;

	ft_colorcheck(s, line);
	i = 0;
	r = ft_atoi(line, &i);
	i++;
	g = ft_atoi(line, &i);
	i++;
	b = ft_atoi(line, &i);
	i++;
	if (r > 255 || g > 255 || b > 255)
		ft_error("color resolution", s);
	if (c == 'C')
		s->tex.c = r * 256 * 256 + g * 256 + b;
	else if (c == 'F')
		s->tex.f = r * 256 * 256 + g * 256 + b;
	if (s->tex.c >= 2147483647 || s->tex.c >= 2147483647)
		ft_error("color", s);
}

int		ft_exit(t_mother *s)
{
	ft_esc(s);
	return (0);
}

int		ft_screenresize(t_mother *s)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	mlx_get_screen_size(s->win.ptrmlx, &width, &height);
	if (s->win.winwidth >= width)
		s->win.winwidth = width;
	if (s->win.winheight >= height)
		s->win.winheight = height;
	return (0);
}

int		looper(t_mother *s)
{
	raycaster(s);
	return (0);
}

void	ft_distbuf(t_mother *s)
{
	if (s->spr.distbuffer)
		s->spr.distbuffer[s->ray.rayi] = s->img.perpwalldist;
}
