#include "../so_long.h"

void	init_map(char *path)
{
	t_data	*data;
	int		value;

	data = malloc(1 * sizeof(t_data));
	if (data == NULL)
		value = 1;
	else
		value = check_map(path, data);

	if (value == 0)
		start(data);
	else if (value != 1)
	{
		// clean data before quit the session
	}
	exit (error_handler(value))
}