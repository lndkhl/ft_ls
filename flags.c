#include "tinker.h"

//checks argument vector for flags
int	flag_check(char **av, int *flags)
{
	int	i;

	i = 0;
	while (av[++i] != NULL)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			if(!is_valid(av[i], flags))
				return (-1);
	}
	return (1);
}

//populates the directories and files arrays in main
int	parse(char **av, int *flags, char **directories, char **files)
{
	
	int	i;
	char *append;
	
	i = 0;
	while (av[++i] != NULL && av[i][0] == '-')
	{
		if (ft_strlen(av[i]) > 1)
			if (!flag_check(av, flags))
				return (-1);
	}
	while (av[i] != NULL)
	{
		if (is_d((append = ft_strdup(av[i]))))
			push(directories, append);
		else if (is_file((append = ft_strdup(av[i]))))
				push(files, append);
		else
			return (print_invalid());
		if (append)
			ft_strdel(&append);			
		i++;
	}
	return (1);
}

//checks the validity of flags
int	is_valid(char *av_i, int *flags)
{
	int	i;

	i = 0;
	while (av_i[++i] != '\0')
	{
		if (av_i[i] == 'l')
			*flags = *flags | 1;
		else if (av_i[i] == 'a')
			*flags = *flags | 2;
		else if (av_i[i] == 'r')
			*flags = *flags | 4;
		else if (av_i[i] == 'R')
			*flags = *flags | 8;
		else if (av_i[i] == 't')
			*flags = *flags | 16;
		else
			return (print_illegal(av_i[i]));
	}	
	return (1);
}

//creates linked lists of the provided directories' contents
int	init_directories(char **directories, ls **behemoth)
{
	int	i;
	int j;

	i = 0;
	if (directories[0] == NULL)
		return (-1);
	while (behemoth[i] != NULL)
		i++;
	j = 0;
	while (directories[j] != NULL)
	{
		behemoth[i] = init_list(directories[j]);
		i++;
		j++;
	}
	behemoth[i] = NULL;
	return (1);
}
