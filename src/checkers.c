#include "../includes/types.h"
bool	is_prog_valid(t_prog *prog)
{
	if (prog == NULL)
		return (false);
	if (prog->info == NULL)
		return (false);
	if (prog->mlx == NULL)
		return (false);
	return (true);
}

