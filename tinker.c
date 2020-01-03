#include "tinker.h"

//appends node (param1) to linked list (param2)
int    	add_node(ls *node, ls **list)
{
	ls	*crsr;

	if(!(node) || !(*list))
	{
		perror("add_node");
		return(-1);
	}
	crsr = *list;
	while(crsr->next)
		crsr = crsr->next;
	crsr->next = node;
	node->prev = crsr;
	return (1);
}

//determines if a given node is a directory
int	is_dir(ls *node)
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

//returns the last node in a given linked list
ls		*seek_end(ls *list)
{
	ls	*temp;

	if(!(list))
	{
		perror("seek_end");
		return (NULL);
	}
	temp = (list);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

//updates the absolute path variable of a node
char		*path_append(const char *path, const char *name)
{
	char	*temp;
	char	*appended;

	if (!(path) || !(name))
	{
		perror("path_append");
		return (NULL);
	}
	temp = ft_strjoin(path, "/");
	appended = ft_strjoin(temp, name);
	ft_strdel(&temp);
	return (appended);
}
