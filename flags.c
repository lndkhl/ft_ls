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
	nonexistant = NULL;
	directories = NULL;
	files = NULL;
	while (av[i] != NULL && av[i][0] == '-')
		i++;
	while (av[i++] != NULL)
	{
		append = ft_strdup(av[i - 1]);
		if (is_d(append))
			directories = push(directories, append);
		else if (is_file(append))
			files = push(files, append);
		else
			nonexistant = push(nonexistant, append);
		free(append);
	}
	if (print_nonexistant(nonexistant) && (!files && !directories))
		return (NULL);;
	behemoth = init(flags, files, directories, behemoth);
	return (behemoth);
}
