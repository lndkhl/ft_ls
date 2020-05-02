/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:00:08 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 13:21:45 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && (i + ft_strlen(needle)) <= len)
	{
		if ((ft_strncmp(&haystack[i], needle, ft_strlen(needle))) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
