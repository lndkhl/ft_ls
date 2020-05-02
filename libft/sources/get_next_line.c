/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:32:19 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 09:25:18 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			cleanup(const int fd, char **line, char **arr, char *temp)
{
	if (!(*line = ft_strdup(arr[fd])))
		return (-1);
	ft_strdel(&arr[fd]);
	ft_strdel(&temp);
	return (1);
}

static int			line_ptcl(const int fd, char **line, char **arr, char *temp)
{
	if (!(*line = ft_strsub(arr[fd], 0, (ft_strchr(arr[fd], '\n') - arr[fd]))))
		return (-1);
	ft_strdel(&temp);
	if (!(temp = ft_strsub(ft_strchr(arr[fd], '\n') + 1, 0,\
						ft_strlen(arr[fd]) - ft_strlen(*line))))
		return (-1);
	ft_strdel(&arr[fd]);
	if (!(arr[fd] = ft_strdup(temp)))
		return (-1);
	ft_strdel(&temp);
	return (1);
}

static int			loop_read(const int fd, char **line, char **arr, char *temp)
{
	char	*t2;
	int		i;

	while ((i = read(fd, temp, BUFF_SIZE)))
	{
		if (!(t2 = (arr[fd]) ? ft_strjoin(arr[fd], temp) : ft_strdup(temp)))
			return (-1);
		ft_strdel(&arr[fd]);
		if (!(arr[fd] = ft_strdup(t2)))
			return (-1);
		ft_strdel(&t2);
		if (ft_strchr(arr[fd], '\n'))
			return (line_ptcl(fd, line, arr, temp));
		else if (i < BUFF_SIZE)
			return (cleanup(fd, line, arr, temp));
		ft_strdel(&temp);
		if (!(temp = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	if (i == 0 && arr[fd][0])
		return (cleanup(fd, line, arr, temp));
	ft_strdel(&temp);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char		*arr[4096];
	char			*temp;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(arr[fd]) && !(arr[fd] = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!(temp = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (ft_strchr(arr[fd], '\n'))
		return (line_ptcl(fd, line, arr, temp));
	return (loop_read(fd, line, arr, temp));
}
