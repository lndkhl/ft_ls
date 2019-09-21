/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:27:05 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/22 17:30:05 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordcount(const char *i, char c)
{
	size_t	b;
	size_t	a;
	size_t	j;
	char	*p;

	b = 0;
	a = 0;
	p = (char *)i;
	while (p[b++])
	{
		j = 0;
		if (p[b] != c)
			a++;
		while (p[b + j] != c && p[b + j] != '\0')
			j++;
		b += j;
	}
	return (a);
}
