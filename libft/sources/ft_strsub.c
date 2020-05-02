/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:59:18 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/15 03:34:01 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*n;
	size_t		i;

	n = ft_strnew(len);
	if (!n || !s)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		n[i++] = s[start++];
	return (n);
}
