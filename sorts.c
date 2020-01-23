#include "tinker.h"

ls		*sort(ls *list)
{
	ls	*temp;
	ls	*sort;
	ls	*head;
	int j;
	int	i;

	j = 0;
	head = list;
	sort = NULL;
	if (!list)
	{
		perror("sort");
		return (NULL);
	}
	temp = list;
	while (temp)
	{
		j++;
		temp = temp->next;
	}
	ft_putnbr(j);
	ft_putchar('\n');
	while ((temp = list) && (i = j--))
	{
		head = temp;
		while ((temp) && i--)
		{
			if (head->stat_buff->st_mtime < temp->stat_buff->st_mtime)
				head = temp;
			else if (head->stat_buff->st_mtime == temp->stat_buff->st_mtime && head->stat_buff->st_mtimespec.tv_nsec < temp->stat_buff->st_mtimespec.tv_nsec)
				head = temp;
			temp = temp->next;
		}
		if (head == list)
			list = list->next;
		else if (head->prev)
			head->prev->next = head->next;
		if (head->next)
			head->next->prev = head->prev;
		if (!sort)
			sort = head;
		else
		{
			temp = seek_end(sort);
			temp->next = head;
			head->next = NULL;
			head->prev = temp;
		}
	}
	return (sort);
}