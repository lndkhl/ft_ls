#include "tinker.h"

//initializes a node
ls	*init_ls_node(const char *name, const char *path)
{
	ls		*node;

	if (!(node = (ls *)malloc(sizeof(ls))))
	{
		perror("init_ls_node malloc");
		return (NULL);;
	}
	if (name == NULL)
	{
		perror("init_ls_node name");
		return (NULL);
	}

	node->next = NULL;
	node->prev = NULL;
	node->name = ft_strdup(name);
	node->abs_path = ft_strdup(path);
	if (lstat(node->abs_path, node->stat_buff) == -1)
	{
		perror("lstat at init");
		return(NULL);
	}
	return (node);
}

//initializes a list of the files in a given directory
ls	*init_list(const char *path)
{
	DIR     		*d;
	ls				*list;
	struct dirent	*dir_struct;
	char			*appended;

	list = NULL;
	appended = ((path[0] == '/') || (path[0] == '~') == 0) \
	? ft_strdup(path) : p_append(".", path);
	if (!(d = opendir(appended)))
		return (NULL);
	ft_strdel(&appended);
	while ((dir_struct = readdir(d)))
	{
		appended = p_append(path, dir_struct->d_name);
		list = add_node((init_ls_node(dir_struct->d_name, appended)), list);
		ft_strdel(&appended);
	}
	closedir(d);
	return (list);
}

//initializes the directory from which the function is called
ls	*init_cwd()
{
	ls	*cwd;

	return (cwd = init_list("."));
}

int	init_files(char **files, ls **behemoth)
{
	int	i;
	int j;

	i = 0;
	if (!(files[0]))
		return (0);
	while (behemoth[i] != NULL)
		i++;
	j = -1;
	while (files[++j] != NULL)
		behemoth[i++] =  init_ls_node(files[j], files[j]);
	return (1);
}
