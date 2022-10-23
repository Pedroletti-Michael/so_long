#include "../so_long.h"

int	init_map(char *path)
{
	t_data	*data;
	int		value;

	data = malloc(1 * sizeof(t_data));
	if (data == NULL)
		value = 1;
	else
	{
		data->map->fd = open(path, 1);
		value = check_map(data);
	}
	if (value == 0)
		value = start(data);
	else if (value != 1)
	{
		free_ptr((void *)&data);
	}
	return (value);
}

int	check_map_name(char *name)
{
	int	len;
	int	dot;
	int b;
	int e;
	int	r;

	len = ft_strlen(name);
	dot = len - 4;
	b = len - 3;
	e = len - 2;
	r = len - 1;
	if (name[r] == 'r' && name[e] == 'e' && name[b] == 'b' && name[dot] == '.')
		return (1);
	return (0);
}

int	check_file_presence(char *path)
{
	int	fd;
	int value;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		value = 0;
	else
		value = 1;
	close (fd);
	return (value);
}