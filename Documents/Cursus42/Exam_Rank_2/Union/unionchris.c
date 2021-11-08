#include <unistd.h>

int main (int ac, char ** av)
{
    int tab[260];
    int i;

    if (ac == 3)
    {
        for (i = 0; i < 260; ++i)
            tab[i] = 0;
        while(*av[1])
        {
            if (!tab[(int)*av[1]])
            {
                tab[(int)*av[1]] = 1;
                write (1, av[1], 1);
            }
            ++av[1];
        }
        while (*av[2])
        {
            if (!tab[(int)*av[2]])
            {
                tab[(int)*av[2]] = 1;
                write (1, av[2], 1);
            }
            ++av[2];
        }
    }
    write (1, "\n", 1);
    return (0);
}
