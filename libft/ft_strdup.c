/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:16:47 by lnkambul          #+#    #+#             */
/*   Updated: 2019/07/18 11:06:08 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*d;
	char	*p;

	if (!(d = ft_strnew(ft_strlen(s))))
		return (NULL);
	p = d;
	while (*s)
		*d++ = *s++;
	return (p);
}
