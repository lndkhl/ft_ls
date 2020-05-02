/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:53:19 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/03 18:34:52 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)ft_memalloc(++size);
	if (!s)
		return (NULL);
	ft_memset(s, '\0', size);
	return (s);
}
