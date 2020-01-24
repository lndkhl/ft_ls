#include "tinker.h"

int	main(int ac, char **av)
{
	//variable that tracks the selected flags
	int				flags;
	//directories specified
	static char		*directories[L_MAX];
	//files specified
	static char		*files[L_MAX];
	//2D array of the linked lists containing everything
	static ls		*behemoth[L_MAX];

	int i;

	flags = 0;
	i = -1;
	while (++i < L_MAX)
	{
		directories[i] = NULL;
		files[i] = NULL;
		behemoth[i] = NULL;
	}
	//checks if flags/files have been specified
	if (ac > 1)
	{
		if (!parse(av, &flags, directories, files))
			return(-1);
		else
		{
			init_files(files, behemoth);
			init_directories(directories, behemoth);
			print(behemoth, &flags);
		}
	}
	//default behaviour, prints the current working directory
	else
	{
		behemoth[0] = init_cwd();
		print(behemoth, &flags);
	}
	//clean(behemoth);
	//clean_string(directories);
	//clean_string(files);
	//sleep(20000);
	return (0);
}
