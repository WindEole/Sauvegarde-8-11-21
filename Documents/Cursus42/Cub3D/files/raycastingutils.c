/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:29:16 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/25 16:55:52 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_ceiling(t_mother *s, int drawstart)
{
	int		i;

	i = 0;
	verticalline(i, drawstart, s->tex.c, s);
}

void	ft_floor(t_mother *s, int drawend)
{
	int		i;

	i = s->win.winheight - 1;
	verticalline(drawend, i, s->tex.f, s);
}

void	ftmlxpixel(t_mother *s, int x, int y, int color)
{
	char *tmp;

	tmp = s->img.adress + (y * s->img.linesize + x * (s->img.bits / 8));
	*(unsigned int *)tmp = color;
}

void	verticalline(int drawstart, int drawend, int color, t_mother *s)
{
	while (drawstart <= drawend)
	{
		ftmlxpixel(s, s->ray.rayi, drawstart, color);
		drawstart++;
	}
}

void	verticalline2(t_mother *s, unsigned int *texture)
{
	int i;

	i = 0;
	while (s->img.drawstart <= s->img.drawend)
	{
		s->img.color = texture[i * 64];
		ftmlxpixel(s, s->ray.rayi, s->img.drawstart, s->img.color);
		i++;
		s->img.drawstart++;
	}
}
