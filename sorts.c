#include "tinker.h"

//sorts list by last modification date and time
ls		*sort(ls *list, int type)
{
	ls	*temp;
	ls	*sort;
	ls	*head;
	int	j;

	sort = NULL;
	j = count_nodes(list);
	while ((list) && j--)
	{
		head = list;
		temp = list->next;
		while (temp)
		{
			head = compare(head, temp, type);
			temp = temp->next;
		}
		if (head == list)
			list = list->next;
		else if (head->prev)
			head->prev->next = head->next;
		if (head->next)
			head->next->prev = head->prev;
		sort = update_sort(sort, head);
	}
	return (sort);
}

int		count_nodes(ls *temp)
{
	ls	*crsr;
	int	j;

	j = 0;
	crsr = temp;
	while (crsr)
	{
		j++;
		crsr = crsr->next;
	}
	return (j);
}


ls		*compare(ls *head, ls *temp, int type)
{
	if (type == 1)
	{
		if (head->stat_buff->st_mtime < temp->stat_buff->st_mtime)
				return (temp);
		else if (head->stat_buff->st_mtime == temp->stat_buff->st_mtime && head->stat_buff->st_mtimespec.tv_nsec < temp->stat_buff->st_mtimespec.tv_nsec)
				return (temp);
		return (head);
	}
	else if (type == 0)
	{
		if (ft_strcmp(temp->name, head->name) < 1)
			return temp;
		return (head);
	}
	else
		return (NULL);
}

ls		*update_sort(ls *sort, ls *head)
{
	ls	*temp;

	temp = NULL;
		if (!(temp = seek_end(sort)))
		{
			sort = head;
			head->next = NULL;
			head->prev = NULL;
		}
		else
		{
			temp->next = head;
			head->next = NULL;
			head->prev = temp;
		}
	return (sort);
}