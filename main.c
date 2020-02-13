/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:12 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 10:00:03 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int	main(int ac, char **av)
{
	int			flags;
	t_lust		*behemoth;
	t_cont		*nonexistent;
	t_lust		*crsr;

	flags = 0;
	if (ac > 1)
		if (!flag_check(av, &flags))
			return (0);
	behemoth = NULL;
	nonexistent = NULL;
	behemoth = parse(av, &flags, behemoth, nonexistent);
	if (!behemoth)
		return 0;
	crsr = behemoth;
	while (crsr) 
	{
		if (crsr->prev)
			ft_putchar('\n');
		print(crsr->list, &flags);
		crsr = crsr->next;
	}
	behemoth = clean(behemoth);
	sleep(30);
	return (0);
}
