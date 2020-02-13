/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:30 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 09:59:55 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int		flag_check(char **av, int *flags)
{
	int	i;

	i = 0;
	while (av[++i] != NULL && av[i][0] == '-')
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			if (!is_valid(av[i], flags))
				return (0);
	}
	return (1);
}

void	parse(char **av, int *flags, t_lust *behemoth, t_cont *nonexistant)
{
	int		i;
	char	*append;
	t_cont	*directories;
	t_cont	*files;

	i = 1;
	append = NULL;
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
		exit(0);
	init(flags, files, directories, behemoth);
}
