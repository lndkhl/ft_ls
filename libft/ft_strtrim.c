/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:55:59 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 14:13:49 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(const char *s)
{
	unsigned int	ws;
	unsigned int	i;
	size_t			j;
	char			*n;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return ((char *)s);
	ws = 0;
	i = 0;
	while (s[i] == 32 || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		ws++;
	}
	j = ft_strlen(s) - 1;
	while ((s[j] == 32 || s[j] == '\t' || s[j] == '\n') && (j-- > i))
		ws++;
	j = (unsigned int)ft_strlen(s) - ws;
	if (!(n = ft_strsub(s, i, j)))
		return (NULL);
	return (n);
}
