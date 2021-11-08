/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:18:42 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 18:14:03 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	raycaclculinit(t_mother *s)
{
	s->img.camerax = 2 * s->ray.rayi / (double)s->win.winwidth - 1;
	s->img.raydirx = s->img.dirx + s->ray.planex * s->img.camerax;
	s->img.raydiry = s->img.diry + s->ray.planey * s->img.camerax;
	s->img.mapx = s->ply.px;
	s->img.mapy = s->ply.py;
	s->img.deltadistx = fabs(1 / s->img.raydirx);
	s->img.deltadisty = fabs(1 / s->img.raydiry);
	s->ray.hit = 0;
}

void	raycalculside(t_mother *s)
{
	if (s->img.raydirx < 0)
	{
		s->img.stepx = -1;
		s->img.sidedistx = (s->ply.px - s->img.mapx) * s->img.deltadistx;
	}
	else
	{
		s->img.stepx = 1;
		s->img.sidedistx = (s->img.mapx + 1.0 - s->ply.px)
			* s->img.deltadistx;
	}
	if (s->img.raydiry < 0)
	{
		s->img.stepy = -1;
		s->img.sidedisty = (s->ply.py - s->img.mapy) * s->img.deltadisty;
	}
	else
	{
		s->img.stepy = 1;
		s->img.sidedisty = (s->img.mapy + 1.0 - s->ply.py) *
			s->img.deltadisty;
	}
}

void	rayhit(t_mother *s)
{
	while (s->ray.hit == 0)
	{
		if (s->img.sidedistx < s->img.sidedisty)
		{
			s->img.sidedistx += s->img.deltadistx;
			s->img.mapx += s->img.stepx;
			s->img.side = 0;
		}
		else
		{
			s->img.sidedisty += s->img.deltadisty;
			s->img.mapy += s->img.stepy;
			s->img.side = 1;
		}
		if (s->map.map[s->img.mapx][s->img.mapy] == '1')
			s->ray.hit = 1;
	}
}

void	ray(t_mother *s)
{
	s->ray.rayi = 0;
	while (s->ray.rayi < s->win.winwidth)
	{
		raycaclculinit(s);
		raycalculside(s);
		rayhit(s);
		if (s->img.side == 0)
			s->img.perpwalldist = (s->img.mapx - s->ply.px
				+ (1 - s->img.stepx) / 2) / s->img.raydirx;
		else
			s->img.perpwalldist = (s->img.mapy - s->ply.py
				+ (1 - s->img.stepy) / 2) / s->img.raydiry;
		s->img.lineheight = (int)(s->win.winheight / s->img.perpwalldist);
		s->img.drawstart = -s->img.lineheight / 2 + s->win.winheight / 2;
		if (s->img.drawstart < 0)
			s->img.drawstart = 0;
		s->img.drawend = s->img.lineheight / 2 + s->win.winheight / 2;
		if (s->img.drawend >= s->win.winheight)
			s->img.drawend = s->win.winheight - 1;
		ft_textures(s);
		ft_ceiling(s, s->img.drawstart);
		ft_floor(s, s->img.drawend);
		ft_distbuf(s);
		s->ray.rayi++;
	}
}

void	raycaster(t_mother *s)
{
	int		u;

	u = 0;
	raycastfree(s);
	if (!(s->spr.distbuffer = malloc(sizeof(double)
		* s->win.winwidth + 1)))
		ft_error("malloc", s);
	while (u < s->win.winwidth)
	{
		s->spr.distbuffer[u] = 0;
		u++;
	}
	ray(s);
	ft_sprites(s);
	if (s->map.save == 1)
		ft_save(s);
	mlx_put_image_to_window(s->win.ptrmlx, s->win.ptr, s->img.ptrimg, 0, 0);
	mlx_hook(s->win.ptr, 33, 1L << 17, ft_exit, s);
	mlx_loop_hook(s->win.ptrmlx, looper, s);
	mlx_hook(s->win.ptr, 2, 1L << 0, key_hook, s);
	mlx_hook(s->win.ptr, 3, 1L << 1, key_hook, s);
	mlx_loop(s->win.ptrmlx);
}
