/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:29:07 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 17:51:06 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		ft_isamap(t_mother *s)
{
	int		i;
	int		j;
	int		wrong;

	i = s->map.mapstart;
	wrong = 0;
	while (i < s->map.linenb)
	{
		j = 0;
		while (s->map.map[i][j] && j < s->map.linesize)
		{
			if (s->map.map[i][j] != '0' && s->map.map[i][j] != '1'
				&& s->map.map[i][j] != '2' && s->map.map[i][j] != ' ')
				wrong = 1;
			j++;
		}
		if (wrong == 1)
		{
			ft_error("char", s);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_playerinit(t_mother *s, int *i, int *j, char *line)
{
	if (s->ply.px != 1 || s->ply.py != 1)
		ft_error("multiplayer", s);
	s->map.map[*i][*j] = '0';
	s->ply.px = *i + 0.5;
	s->ply.py = *j + 0.5;
	if (line[*j] == 'N')
	{
		s->img.dirx = -1;
		s->ray.planey = 0.66;
	}
	if (line[*j] == 'S')
	{
		s->img.dirx = 1;
		s->ray.planey = -0.66;
	}
	if (line[*j] == 'E')
	{
		s->img.diry = 1;
		s->ray.planex = 0.66;
	}
	if (line[*j] == 'W')
	{
		s->img.diry = -1;
		s->ray.planex = -0.66;
	}
}

void	ft_char(char *line, t_mother *s)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\0' && line[i] != '0'
			&& line[i] != '1' && line[i] != '2' && line[i] != ' ' &&
			line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' &&
			(line[0] == '1' || line[0] == '0' || line[0] == '2'
			|| line[0] == ' '))
			ft_error("char", s);
		i++;
	}
}

int		ft_mapfill(t_mother *s, char *line, int i)
{
	int		j;

	j = 0;
	ft_char(line, s);
	while (line[j] != '\0' &&
		(line[0] == '1' || line[0] == '0' || line[0] == '2' || line[0] == ' '))
	{
		if (line[j] == '0' || line[j] == '1')
			s->map.map[i][j] = line[j];
		if (line[j] == '2')
			plyparse(s, i, j);
		else if (line[j] == ' ')
			s->map.map[i][j] = ' ';
		else if (line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W')
		{
			ft_playerinit(s, &i, &j, line);
			s->map.map[i][j] = '0';
		}
		j++;
	}
	if (s->map.map[i] != NULL)
		s->map.map[i][j] = '\0';
	return (1);
}

int		ft_mapparse(t_mother *s, char *mapfile)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	ret = 1;
	i = 0;
	fd = open(mapfile, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line[0] != '1' || line[0] != '0')
			ft_getmapargs(s, line);
		if (line[0] == ' ')
			ft_error("config", s);
		if (s->tex.no != NULL && s->tex.so != NULL && s->tex.ea != NULL &&
				s->tex.we != NULL && s->tex.s != NULL && s->tex.c != 0
				&& s->tex.f != 0 && line[0] != ' ')
			ft_mapimalloc(s, i, line);
		i++;
		free(line);
	}
	ft_isamap(s);
	ft_checkassign(s);
	return (1);
}
