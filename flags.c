#include "tinker.h"

//checks argument vector for flags
int	flag_check(char **av, int *flags)
{
	int	i;

	i = 0;
	while (av[++i] != NULL && av[i][0] == '-')
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			if(!is_valid(av[i], flags))
				return (-1);
	}
	return (1);
}

//populates the directories and files arrays in main
int	parse(char **av, char **directories, char **files, char **nonexistant)
{
	int	i;
	char *append;
	
	i = 1;
	append = NULL;
	while (av[i] != NULL && av[i][0] == '-')
		i++;
	while (av[i] != NULL)
	{
		append = ft_strdup(av[i]);
		if (is_d(append))
			push(directories, append);
		else if (is_file(append))
			push(files, append);
		else
			push(nonexistant, append);
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

//creates linked list of files not found
int	print_nonexistant(char **nonexistant)
{
	int	i;

	i = 0;
	if (nonexistant[i] == NULL)
		return (0);
	while (nonexistant[i] != NULL)
		print_invalid(nonexistant[i++]);
	return (1);
}

//initializes the containers
int	init(char **nonexistant, char **files, char **directories, ls **behemoth)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	print_nonexistant(nonexistant);
	i = init_files(files, behemoth);
	j = init_directories(directories, behemoth);
	if (!i && !j)
	{
		behemoth[0] = init_cwd();
		return (0);
	}
	return (1);
}
