#include "tinker.h"

/*determines if a given node is a directory*/
int	is_dir(t_ls *node)
{
	if (!(node))
	{
		perror("is_dir");
		return (-1);
	}
	if (ft_strcmp((node)->name, ".") == 0 || ft_strcmp((node)->name, "..") == 0)
		return (0);
	if (((node)->stat_buff->st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

/*returns the last node in a given linked list*/
t_ls		*seek_end(t_ls *list)
{
	t_ls	*temp;

	if(!(list))
		return (NULL);
	temp = (list);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

