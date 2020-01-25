#include "tinker.h"

//sorts list by last modification date and time
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

//sorts list lexicographically
ls	*lex_sort(ls *list)
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
	while ((temp = list) && (i = j--))
	{
		head = temp;
		while ((temp) && i--)
		{
			if ((ft_strcmp(head->name, temp->name)) < 1)
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