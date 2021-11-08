/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interFlo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:39:06 by iderighe          #+#    #+#             */
/*   Updated: 2021/05/31 15:39:31 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

void    ft_solve(char *s1, char *s2)
{
    int i;
    int ascii[256] = {0};

    i = -1;
    while (s2[++i])
        if (ascii[(int)s2[i]] == 0)
            ascii[(int)s2[i]] = 1;
    i = -1;
    while (s1[++i])
        if (ascii[(int)s1[i]] == 1)
        {
            ascii[(int)s1[i]] = 2;
            write(1, &s1[i], 1);
        }
}

int        main(int argc, char **argv)
{
    if (argc == 3)
        ft_solve(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}
