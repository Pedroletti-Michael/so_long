#include "../includes/so_long.h"

int	close_mlx_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_mlx_win(vars);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		player_move(keycode,vars);
	return (0);
}
