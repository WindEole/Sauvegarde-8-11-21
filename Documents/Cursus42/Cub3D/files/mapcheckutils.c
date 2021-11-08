/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:48:04 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/25 16:52:09 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		argcheck(char *av, int cas)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	if (cas == 2 && ft_strcmp(av, "--save") == 0 && i == 6)
		return (1);
	else if (cas == 1 && av[i - 1] == 'b' && av[i - 2] == 'u'
		&& av[i - 3] == 'c' && av[i - 4] == '.' && i >= 4)
		return (1);
	else
		return (0);
}

int		parseline(char *line, t_mother *s, int nbline)
{
	int		j;
	int		i;

	j = 0;
	if (!(s->map.map[nbline] = malloc(sizeof(char *) * ft_strlen(line) + 1)))
		return (0);
	while (line[j] != '\0')
	{
		s->map.map[nbline][j] = line[j];
		j++;
	}
	s->map.map[nbline][j] = '\0';
	i = 0;
	while (s->map.map[i++])
		free(s->map.map[i]);
	return (0);
}

int		ft_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\v'
		|| str == '\r' || str == '\f' || str == '\n')
		return (1);
	return (0);
}

void	ft_ismapopen(t_mother *s)
{
	int		i;
	int		j;

	i = s->map.mapstart;
	j = 0;
	while (s->map.map[i][0] < s->map.linenb)
	{
		if (s->map.map[s->map.linenb - 1][j] != '1')
			ft_error("map open", s);
		j++;
	}
}

void	ft_mapclose(t_mother *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s->map.map[s->map.linenb - 1][j] != '\0')
	{
		if (s->map.map[s->map.linenb - 1][j] != '1')
			ft_error("map open", s);
		j++;
	}
	i = s->map.mapstart + 1;
	while (s->map.map[i] && i < (s->map.linenb - 1))
	{
		if (s->map.map[i][0] != '1')
			ft_error("map open", s);
		if (s->map.map[i][ft_strlen(s->map.map[i]) - 1] != '1')
			ft_error("map open", s);
		ft_ismapopen(s);
		i++;
	}
}
