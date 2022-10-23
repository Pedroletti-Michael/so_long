#include "../so_long.h"

static int	verify_width_map(t_data *data, char *content, int height_now)
{
	if (data->map->width < 4)
		return (6);
	if (ft_verify_str(content, "1", data->map->width) == 0)
	{
		if (((int)ft_strlen(content)) != data->map->width && height_now > 0)
			return (7);
		content[data->map->width] = '\0';
		return (0);
	}
	if (ft_verify_str(content, "10ECPJ", data->map->width) == 0)
	{
		if (content[0] != '1' || content[data->map->width - 1] != '1')
			return (7);
		if (((int)ft_strlen(content)) - 1 != data->map->width)
			return (7);
		content[data->map->width] = '\0';
		return (0);
	}
	return (8);
}

static	int	read_map_while(t_data *data, int *a, int i)
{
	char	*tmp_map;
	int		value;

	tmp_map = get_next_line(data->map->fd);
	if (tmp_map == NULL)
		free_ptr((void *)&tmp_map);
	if (data->map->width == 0)
		data->map->width = ft_strlen(tmp_map) - 1;
	value = verify_width_map(data, tmp_map, *a);
	if (value == -1)
	{
		data->map->height = *a + 1;
		free_ptr((void **)&tmp_map);
		return (6);
	}
	tmp_map = data->map->map[i];
	free_ptr((void *)&data->map->map[i]);
	data->map->map[i] = tmp_map;
	free_ptr((void **)&tmp_map);
	return (0);
}


static	int	verify_counts(t_objects objects, t_data *data, int a)
{
	int	value;

	value = 0;
	if (objects.c < 1)
		value = 2;
	else if (objects.p != 1)
		value = 3;
	else if (objects.e != 1)
		value = 4;
	else if (a - 1 < 4)
		value = 5;
	else if (a - 1 > 3)
		data->map->height = a - 1;
	return (value);
}


static	int	read_map(t_data *data)
{
	t_objects	objects;
	int			a;

	a = 0;
	data->map->width = 0;
	init_objects(&objects);
	while (data->map->map == 0 || data->map->map[a - 1] != 0
		|| a == 0)
	{
		if (read_map_while(data, &a, -1) == -1)
			return (-1); // before turning down the system I need to clean the objets
		objects.e += ft_verify_objects(data->map->map[a], 'E');
		objects.c += ft_verify_objects(data->map->map[a], 'C');
		objects.p += ft_verify_objects(data->map->map[a], 'P');
		a++;
	}
	return (verify_counts(objects, data, a));
}


int	check_map(t_data *data)
{
	int	value;

	value = 0;
	data->map = malloc(1 * sizeof(t_map));
	if (data->map == NULL)
		return (1);
	data->map->map = NULL;
	value = read_map(data);
	return (value);
}