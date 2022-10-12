void	init_objects(t_objects *objects)
{
	objects->c = 0;
	objects->p = 0;
	objects->e = 0;
}

int	ft_verify_objects(char *line, char object)
{
	int	a;

	a = 0;
	if (line != NULL)
	{
		if (ft_strchr(line, object))
			a++;
		return (a);
	}
	return (a);
}

void	init_tmp_map(char *map, int a)
{
	tmp_map = get_next_line(data->map->fd);
	if (tmp_map == NULL)
	{
		free_ptr((void *)&tmp_map);
		return (0);
	}
}