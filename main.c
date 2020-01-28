#include "tinker.h"

int	main(int ac, char **av)
{
	int				flags;
	static char		*directories[L_MAX];
	static char		*files[L_MAX];
	static ls		*behemoth[L_MAX];
	int 			i;

	flags = 0;
	i = -1;
	while (++i < L_MAX)
	{
		directories[i] = NULL;
		files[i] = NULL;
		behemoth[i] = NULL;
	}
	if (ac > 1)
		if (!(parse(av, &flags, directories, files)))
			return (0);
	init(files, directories, behemoth);
	print(behemoth, &flags);
	clean_string(files);
	clean_string(directories);
	sleep(30);
	return (0);
}
