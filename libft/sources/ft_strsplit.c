/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:51:50 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/22 17:31:43 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_poparray(char **ptr, const char *p, char c, size_t w)
{
	size_t			i;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	k = 0;
	while (p[k])
	{
		if (p[k] != c && j < w)
		{
			i = 0;
			while (p[k + i] != c && p[k + i] != '\0')
				i++;
			if (!(ptr[j++] = ft_strsub(p, k, i)))
				return (NULL);
			k += i;
		}
		k++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**arr;
	size_t		i;

	if (!s)
		return (NULL);
	i = ft_wordcount(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	if (!(arr = ft_poparray(arr, s, c, i)))
		return (NULL);
	return (arr);
}
