#include "tinker.h"

int	main(int ac, char **av)
{
	ls	*cwd;
	int	flags;

	flags = 0;
	if (!flag_check(av, ac, &flags))
		return(illegal_option);
	if (ac > 1)
		parse(av, ac);
	else
	{
		cwd = init_cwd();
		print(&cwd);
	}
	return (0);
}
