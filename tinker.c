#include "tinker.h"

//appends node (param1) to linked list (param2)
ls    	*add_node(ls *node, ls *list)
{
	ls	*crsr;

	if(!(node))
	{
		perror("add_node");
		return(NULL);
	}
	if (!(list))
	{
		list = node;
		return (list);
	}
	crsr = seek_end(list);
	crsr->next = node;
	node->prev = crsr;
	return (list);
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
		return (NULL);
	temp = (list);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

//updates the absolute path variable of a node
char		*p_append(const char *path, const char *name)
{
	char	*temp;
	char	*slash;
	char	*appended;

	if (!(path) || !(name))
		return (NULL);
	slash = ft_strdup("/");
	temp = ft_strjoin(path, slash);
	appended = ft_strjoin(temp, name);
	free(temp);
	free(slash);
	return (appended);
}
