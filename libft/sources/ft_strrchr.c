/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:13:44 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/11 09:30:06 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	n;

	i = ft_strlen(s);
	n = (char)c;
	if (i == 0 && n != '\0')
		return (NULL);
	if (n == '\0')
		return ((char *)&s[i]);
	while (i > 0 && s[i] != n)
		i--;
	if (i == 0 && s[i] != n)
		return (NULL);
	return ((char *)&s[i]);
}
