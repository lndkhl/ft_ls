#include "tinker.h"

int	flag_check(char **av, int ac, int *flags)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			if(!is_valid(av[i], flags))
				return (-1);
	}
	return (parse(av, ac));
}

int	parse(char **av, int ac)
{
	int	i;
	char	*directories;
	char	*files;
	
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			
}

int	sort(ls **list)
{
	if (!(*list))
	{
		perror("sort");
		return(-1);
	}
	return (1);
}

int	is_valid(char *av_i, int *flags)
{
	int	i;

	i = 0;
	while (av_i[i++] != '\0')
	{
		if (av_i[i] == 'l')
			*flags == *flags | 1;
		else if (av_i[i] == 'a')
			*flags == *flags | 2;
		else if (av_i[i] == 'r')
			*flags == *flags | 3;
		else if (av_i[i] == 'R')
			*flags == *flags | 4;;
		else if (av_i[i] == 't')
			*flags == *flags | 5;
		else
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(av_i[i]);
			ft_putchar('\n');
			ft_putendl("usage ft_ls [l,r,a, R, t] [file ...]");
			return (-1);	 		
		}
	}	
	return (1);
}
