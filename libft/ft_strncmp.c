/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:35:00 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 13:20:35 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (a[i] == '\0' && b[i] == '\0')
		return (0);
	while (a[i] != '\0' && b[i] != '\0' && n > 0)
	{
		if (a[i] > b[i])
			return (1);
		else if (a[i] < b[i])
			return (-1);
		i++;
		n--;
	}
	if ((a[i] == '\0' && (b[i] != '\0') && n > 0))
		return (-1);
	else if ((a[i] != '\0' && b[i] == '\0') && n > 0)
		return (1);
	return (0);
}
