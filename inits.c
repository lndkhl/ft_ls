#include "tinker.h"

//initializes a node
ls	*init_ls_node(const char *name, const char *dir_name, const char *path)
{
	ls		*node;

	if (!(node = (ls *)malloc(sizeof(ls))))
		return (NULL);;
	if (name == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->name = ft_strdup(name);
	node->abs_path = ft_strdup(path);
	if (dir_name)
		node->dir_name = ft_strdup(dir_name);
	else
		node->dir_name = NULL;
	ft_memset(node->link_buff, '\0', L_MIN);
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
		list = add_node((init_ls_node(dir_struct->d_name, path, appended)), list);
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

//initializes the nodes corresponding to requested filename
int	init_files(char **files, ls **behemoth)
{
	int		i;
	int 	j;
	char	*dir_name;

	dir_name = NULL;
	i = 0;
	if (!(files[0]))
		return (0);
	while (behemoth[i] != NULL)
		i++;
	j = -1;
	while (files[++j] != NULL)
		behemoth[i++] =  init_ls_node(files[j], dir_name, files[j]);
	return (1);
}
//creates linked lists of the provided directories' contents
int init_directories(char **directories, ls **behemoth)
{
	int i;
	int j;
	int k;

	 i = 0;
	if (directories[0] == NULL)
		return (0);
	while (behemoth[i] != NULL)
		i++;
	k = i;
	j = 0;
	while (directories[j] != NULL)
	{
		behemoth[i] = init_list(directories[j]);
		i++;
		j++;
	}
	sort_dirs(behemoth, k);
	return (1);
}
