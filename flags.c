#include "tinker.h"

int	flag_check(char **av, int ac, int *flags)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			is_valid(av[i], flags);
		else
			return (parse(av, ac));
	}
	return (1);
}

int	parse(char **av, int ac)
{
	int	i;

	i = 0;
	while
	if ()
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
			*flags <<= 1;
		else if (av_i[i] == 'a')
			*flags = ;
		else if (av_i[i] == 'r')
			*flags = ;
		else if (av_i[i] == 'R')
			*flags = ;
		else if (av_i[i] == 't')
			*flags = ;
		else
			return (0);
	}
}
