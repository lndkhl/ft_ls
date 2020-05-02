/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:45:27 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 13:24:52 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	char			*s;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			s = ft_strsub(haystack, i, ft_strlen(needle));
			if (ft_strcmp(s, needle) == 0)
			{
				ft_strdel(&s);
				return ((char *)&haystack[i]);
			}
			ft_strdel(&s);
		}
		i++;
	}
	return (NULL);
}
