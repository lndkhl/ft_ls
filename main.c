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
	int			flags;
	t_lust		*behemoth;

	flags = 0;
	if (ac > 1)
		if (!flag_check(av, &flags))
			return (0);
	behemoth = NULL;
	behemoth = parse(av, &flags, behemoth);
	print(behemoth, &flags);
	clean(behemoth, &flags);
	sleep(30);
	return (0);
}
