/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:12 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:23:19 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int	main(int ac, char **av)
{
	int				flags;
	static char		*directories[L_MAX];
	static char		*files[L_MAX];
	static char		*nonexistant[L_MAX];
	static ls		*behemoth[L_MAX];

	flags = -1;
	while (++flags < L_MAX)
	{
		directories[flags] = NULL;
		files[flags] = NULL;
		nonexistant[flags] = NULL;
		behemoth[flags] = NULL;
	}
	flags = 0;
	if (ac > 1)
		if (!flag_check(av, &flags))
			return (0);
	parse(av, directories, files, nonexistant);
	init(&flags, files, directories, behemoth);
	print(behemoth, &flags);
	clean_string(nonexistant);
	clean_string(files);
	clean_string(directories);
	//sleep(30);
	return (0);
}
