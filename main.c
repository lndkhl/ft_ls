#include "tinker.h"

int	main(int ac, char **av)
{
	ls	*cwd;
	//variable that tracks the selected flags
	int	flags;

	flags = 0;
	//checks if flags/files have been specified
	if (ac > 1)
		if (!flag_check(av, ac, &flags))
			return(-1);
	//default behaviour, prints the content of the current working directory
	else
	{
		cwd = init_cwd();
		print(&cwd);
	}
	return (0);
}
