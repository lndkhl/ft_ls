#include "tinker.h"

int		main(void)
{
	ls	*cwd;

	cwd = init_cwd();
	print(&cwd);
	//print_rev(&cwd);
	//print_rec(&cwd);
	return (0);
}
