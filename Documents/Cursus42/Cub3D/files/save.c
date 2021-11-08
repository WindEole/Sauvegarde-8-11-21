/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:42:18 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/25 17:20:54 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		ft_header(t_mother *s, int fd)
{
	int	bmp;
	int	i;

	bmp = 0;
	i = 0;
	write(fd, "BM", 2);
	bmp = s->win.winwidth * s->win.winheight * 58;
	write(fd, &bmp, 4);
	bmp = 0;
	write(fd, &bmp, 2);
	write(fd, &bmp, 2);
	bmp = 54;
	write(fd, &bmp, 4);
	bmp = 40;
	write(fd, &bmp, 4);
	write(fd, &s->win.winwidth, 4);
	write(fd, &s->win.winheight, 4);
	bmp = 1;
	write(fd, &bmp, 2);
	write(fd, &s->img.bits, 2);
	bmp = 0;
	while (i++ <= 5)
		write(fd, &bmp, 4);
	return (1);
}

int		getimgpixel1(t_mother *s, int x, int y, char *adress)
{
	char	*tmp;

	tmp = adress + (y * s->img.linesize + x * (s->img.bits / 8));
	return (*(unsigned int*)tmp);
}

void	ft_fillfile(t_mother *s, int fd)
{
	int				i;
	int				j;
	unsigned int	*zoub;

	i = 0;
	j = s->win.winheight - 1;
	zoub = NULL;
	if (!(zoub = malloc(sizeof(unsigned int *)
		* s->win.winwidth * s->win.winheight * 58 + 1)))
		ft_error("malloc", s);
	while (j >= 0)
	{
		i = 0;
		while (i < s->win.winwidth)
		{
			zoub[i] = getimgpixel1(s, i, j, s->img.adress);
			write(fd, &zoub[i], 4);
			i++;
		}
		j--;
	}
	free(zoub);
}

void	ft_save(t_mother *s)
{
	int				fd;

	fd = 0;
	system("touch cub.bmp");
	if ((fd == -1) || !(fd = open("cub.bmp", O_WRONLY)))
		ft_error("open", s);
	ft_header(s, fd);
	ft_fillfile(s, fd);
	if (close(fd) == -1)
		ft_error("close", s);
	ft_esc(s);
	exit(0);
}
