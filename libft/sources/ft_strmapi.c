/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:05:26 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 13:19:20 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*t;
	char			*p;

	if (!s || !f)
		return (NULL);
	i = 0;
	t = (char *)ft_strdup(s);
	if (!t)
		return (NULL);
	p = t;
	while (t[i])
	{
		t[i] = (*f)((i), (t[i]));
		i++;
	}
	return (p);
}
