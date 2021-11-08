#include "ft_printf.h"

int	main(int argc, char **argv)
{
	unsigned long long	y;
	int					i[3];
	i[0] = -2;
	i[1] = -2;
	if (argc == 2)
	{
		y = atoi(argv[1]);
		printf("\n===============\n\n%%p -> (%llu)\n\n", y);
		write(1, "ft_printf = [", 13);
		i[0] = ft_printf(" %p ", y);
		printf("]\n   printf = [");
		i[1] = printf(" %p ", y);
		printf("]\n\nRetour ft_printf = [%d]\nRetour    printf = [%d]\n\n", i[0], i[1]);
		return (0);
	}
	else if (argc == 1)
	{
		y = 0;
		while (1)
		{
			printf("\n===============\n\n%%p -> (%llu)\n\n", y);
			write(1, "ft_printf = [", 13);
			i[0] = ft_printf(" %p ", y);
			printf("]\n   printf = [");
			i[1] = printf(" %p ", y);
			printf("]\n\nRetour ft_printf = [%d]\nRetour    printf = [%d]\n\n", i[0], i[1]);
			y++;
			i[2] = 0;
			while (i[2] < 25000000)
				i[2]++;
	}
	return (0);
	}
}
