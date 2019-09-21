/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:39:40 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/11 09:06:52 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	n;

	i = 0;
	n = (char)c;
	if (n == '\0')
		return ((char *)&(s[ft_strlen(s)]));
	while (s[i] != '\0' && s[i] != n)
		i++;
	if (s[i] == '\0')
		return (NULL);
	return ((char *)&s[i]);
}
