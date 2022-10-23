#include "../so_long.h"

char*	error_handler(int value)
{
	if (value == 2)
		return("Map must contain 1 or more coins !");
	if (value == 3)
		return("No or more than 1 start position !");
	if (value == 4)
		return("No or more than 1 exit !");
	if (value == 5)
		return("Map height is too small !");
	if (value == 6)
		return("Map width is too small !");
	if (value == 7)
		return("Wrong construction of the map !");
	if (value == 8)
		return("Wrong construction of the map or letter unknow !");
	if (value == 9)
		return("Wrong file location !");
	if (value == 10)
		return("Wrong file extension !");
	if (value == 11)
		return("No argument given !");
	else
		return("Memory allocation error !");
}

void	clear_map(t_map *map)
{
	close(map->fd);
	while (map->height--)
		free_ptr((void **)&map->map[map->height]);
	free_ptr((void **)&map->map);
	free_ptr((void **)&map);
}

void	close_window(t_data *module)
{
	int	i;

	i = -1;
	mlx_destroy_image(module->vars->mlx, module->sprite->collect);
	mlx_destroy_image(module->vars->mlx, module->sprite->wall);
	mlx_destroy_image(module->vars->mlx, module->sprite->ground);
	mlx_destroy_image(module->vars->mlx, module->sprite->exit);
	while (++i < 4)
		mlx_destroy_image(module->vars->mlx, module->sprite->player[i]);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(module->vars->mlx, module->sprite->enemies[i]);
	free_ptr((void **)&module->sprite->player);
	free_ptr((void **)&module->sprite->enemies);
	free_ptr((void **)&module->sprite);
	mlx_destroy_window(module->vars->mlx, module->vars->win);
	//mlx_destroy_display(module->vars->mlx);
	free_ptr((void **)&module->vars->mlx);
	free_ptr((void **)&module->vars);
}

int	close_all(t_data *module)
{
	close_window(module);
	clear_map(module->map);
	free_ptr((void **)&module->player);
	free_ptr((void **)&module->coin);
	free_ptr((void **)&module);
	exit(0);
	return (0);
}