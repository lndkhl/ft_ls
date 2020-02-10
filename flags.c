/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:30 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:23:35 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//populates the directories and files lists
t_lust	*parse(char **av, int *flags, t_lust *behemoth)
{
	int		i;
	char 	*append;
	t_cont	*nonexistant;
	t_cont	*directories;
	t_cont	*files;
	
	i = 1;
	append = NULL;
	nonexistant = NULL;
	directories = NULL;
	files = NULL;
	while (av[i] != NULL && av[i][0] == '-')
		i++;
	while (av[i] != NULL)
	{
		append = ft_strdup(av[i]);
		if (is_d(append))
			directories = push(directories, append);
		else if (is_file(append))
			files = push(files, append);
		else
			nonexistant = push(nonexistant, append);
		i++;
	}
	if (print_nonexistant(nonexistant) && (!files && !directories))
		return (NULL);;
	behemoth = init(flags, files, directories, behemoth);
	return (behemoth);
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
int	print_nonexistant(t_cont *nonexistant)
{
	t_cont	*temp;

	if (nonexistant == NULL)
		return (0);
	temp = nonexistant;
	while (temp != NULL)
	{
		print_invalid(temp);
		temp = temp->next;
	}
	return (1);
}

//initializes the containers
t_lust	*init(int *flags, t_cont *files, t_cont *directories, t_lust *behemoth)
{
	behemoth = init_files(files, behemoth, flags);
	behemoth = init_directories(directories, behemoth, flags);
	if (!(behemoth))
	{
		behemoth = (t_lust *)malloc(sizeof(t_lust));
		behemoth->list = init_cwd(flags);
		behemoth->prev = NULL;
		behemoth->next = NULL;
		return (behemoth);
	}
	return (behemoth);
}
