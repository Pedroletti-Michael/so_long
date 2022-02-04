#include "../so_long.h"

static int	verify_width_map(t_data *data, char *content, int height_now)
{
	if (data->map->width < 4)
		return (error("The width is too small!"));
	if (ft_verify_str(content, "1", data->map->width) == 0)
	{
		if (((int)ft_strlen(content)) != data->map->width && height_now > 0)
			return (error("Wrong construction of the map!"));
		content[data->map->width] = '\0';
		return (0);
	}
	if (ft_verify_str(content, "10ECPJ", data->map->width) == 0)
	{
		if (content[0] != '1' || content[data->map->width - 1] != '1')
			return (error("Wrong construction of the map!"));
		if (((int)ft_strlen(content)) - 1 != data->map->width)
			return (error("Wrong construction of the map!"));
		content[data->map->width] = '\0';
		return (0);
	}
	return (error("Wrong construction of the map, letter not allowed!"));
}

static int	read_map_while(t_data *data, char **tmp_map, int *a, int b)
{
	tmp_map = (char **)ft_calloc(*a + 2, sizeof(char *));
	if (tmp_map == NULL)
		return (error("Memory allocation error in data.map!"));
	tmp_map[*a] = get_next_line(data->map->fd);
	if (tmp_map[*a] == NULL)
	{
		free_ptr((void **)&tmp_map);
		return (0);
	}
	if (data->map->width == 0)
		data->map->width = ft_strlen(tmp_map[*a]) - 1;
	if (verify_width_map(data, tmp_map[*a], *a) == -1)
	{
		data->map->height = *a + 1;
		free_ptr((void **)&tmp_map[*a]);
		free_ptr((void **)&tmp_map);
		return (-1);
	}
	while (++b < *a)
		tmp_map[b] = data->map->map[b];
	free_ptr((void **)&data->map->map);
	data->map->map = tmp_map;
	return (0);
}

static int	read_map(t_data *data)
{
	t_objects	objects;
	char		**tmp_map;
	int			a;

	a = 0;
	tmp_map = NULL;
	data->map->width = 0;
	init_objects(&objects);
	while (data->map->map == NULL || data->map->map[a - 1] != NULL
		|| a == 0)
	{
		if (read_map_while(data, tmp_map, &a, -1) == -1)
			return (-1);
		objects.e += ft_verify_objects(data->map->map[a], 'E');
		objects.c += ft_verify_objects(data->map->map[a], 'C');
		objects.p += ft_verify_objects(data->map->map[a], 'P');
		a++;
	}
	if (objects.c < 1 || objects.p != 1 || objects.e != 1)
		return (error("Something is missing from the map!"));
	if (a - 1 < 4)
		return (error("The height is too small!"));
	data->map->height = a - 1;
	return (0);
}

static int	check_map_name(char *name)
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
		return (0);
	return (-1);
}

int	check_map(char *name, t_data *data)
{
	data->map = malloc(1 * sizeof(t_map));
	data->map->map = NULL;
	if (data->map == NULL)
		return (error("Allocation memory error during map check !"));
	if (check_map_name(name))
		return (error("File type error ! Use .ber file type !"));
	data->map->fd = open(name, O_RDONLY);
	if (data->map->fd == -1)
		return (error("File does not exist !"));
	if (read_map(data) == -1)
		return (-1);
	return (0);
}
