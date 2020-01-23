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
	if (lstat(path, node->stat_buff) == -1)
	{
		perror("lstat at init");
		return(NULL);
	}
	return (node);
}

//initializes a list of the files in a given directory
ls	*init_list(const char *path)
{
	DIR     	*d;
	ls		*list;
	struct dirent	*dir_struct;
	//char		abs_path[L_MAX];

	list = NULL;
	if (!(path) || !(d = opendir(path)))
	{
		perror("init_list");
		return (NULL);
	}
	dir_struct = readdir(d);
	if (!(list = init_ls_node(dir_struct->d_name, dir_struct->d_name)))
	{
		perror("initial init");
		return (NULL);
	}
	while ((dir_struct = readdir(d)))
		add_node(init_ls_node(dir_struct->d_name, path), &list);
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
		return (-1);
	while (behemoth[i] != NULL)
		i++;
	j = -1;
	while (files[++j] != NULL)
		behemoth[i++] =  init_ls_node(files[j], files[j]);
	return (1);
}
