#include "../so_long.h"

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

int	error(char *message)
{
	ft_printf("ERROR : %s\n", message);
	return (-1);
}
