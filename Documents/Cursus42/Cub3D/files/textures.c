/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:21:01 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 18:21:19 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_sidesone(t_mother *s)
{
	if (s->img.side == 1)
	{
		if (s->img.raydiry < 0)
		{
			s->tex.ptr = mlx_xpm_file_to_image(s->win.ptrmlx,
				s->tex.ea, &s->tex.height, &s->tex.width);
			s->tex.adress = mlx_get_data_addr(s->tex.ptr, &s->tex.bits,
				&s->tex.linesize, &s->tex.endian);
		}
		if (s->img.raydiry >= 0)
		{
			s->tex.ptr = mlx_xpm_file_to_image(s->win.ptrmlx,
				s->tex.we, &s->tex.height, &s->tex.width);
			s->tex.adress = mlx_get_data_addr(s->tex.ptr, &s->tex.bits,
				&s->tex.linesize, &s->tex.endian);
		}
		s->tex.wallhit = s->ply.px + s->img.perpwalldist * s->img.raydirx;
	}
}

void	ft_sidezero(t_mother *s)
{
	if (s->img.side == 0)
	{
		if (s->img.raydirx >= 0)
		{
			s->tex.ptr = mlx_xpm_file_to_image(s->win.ptrmlx,
				s->tex.so, &s->tex.height, &s->tex.width);
			s->tex.adress = mlx_get_data_addr(s->tex.ptr, &s->tex.bits,
				&s->tex.linesize, &s->tex.endian);
		}
		if (s->img.raydirx < 0)
		{
			s->tex.ptr = mlx_xpm_file_to_image(s->win.ptrmlx,
				s->tex.no, &s->tex.height, &s->tex.width);
			s->tex.adress = mlx_get_data_addr(s->tex.ptr, &s->tex.bits,
				&s->tex.linesize, &s->tex.endian);
		}
		s->tex.wallhit = s->ply.py + s->img.perpwalldist * s->img.raydiry;
	}
}

void	ft_textures(t_mother *s)
{
	ft_sidezero(s);
	ft_sidesone(s);
	s->tex.wallhit -= floor(s->tex.wallhit);
	s->tex.texx = s->tex.wallhit * s->tex.width;
	s->tex.step = 1.0 * s->tex.height / s->img.lineheight;
	s->tex.position = (s->img.drawstart - s->win.winheight / 2
		+ s->img.lineheight / 2) * s->tex.step;
	s->tex.texy = 0;
	s->tex.y = s->img.drawstart;
	while (s->tex.y < s->img.drawend)
	{
		s->tex.texy = (int)s->tex.position;
		s->tex.position += s->tex.step;
		s->tex.color = getimgpixel(s->tex.texx, s->tex.texy,
			s->tex.adress, s->tex.bits);
		ftmlxpixel(s, s->ray.rayi, s->tex.y, s->tex.color);
		s->tex.y++;
	}
	if (s->tex.ptr)
		mlx_destroy_image(s->win.ptrmlx, s->tex.ptr);
	s->tex.ptr = NULL;
}

void	raycastfree(t_mother *s)
{
	int endian;

	if (s->img.ptrimg)
		mlx_destroy_image(s->win.ptrmlx, s->img.ptrimg);
	s->img.ptrimg = NULL;
	s->img.ptrimg = mlx_new_image(s->win.ptrmlx, s->win.winwidth,
		s->win.winheight);
	s->img.adress = mlx_get_data_addr(s->img.ptrimg, &s->img.bits,
		&s->img.linesize, &endian);
	if (s->tex.ptr)
		mlx_destroy_image(s->win.ptrmlx, s->tex.ptr);
	s->tex.ptr = NULL;
	if (s->spr.stex)
		mlx_destroy_image(s->win.ptrmlx, s->spr.stex);
	s->spr.stex = NULL;
	s->spr.distbuffer = NULL;
}
