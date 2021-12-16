#include "../includes/so_long.h"

void	start()
{
	t_vars	data;
	initialization(&data);
	// Ouvrir une fenetre avec les elements a partir de la map fournie
	mlx_key_hook(data.win, hook, &data);
	mlx_hook(data.win, 17, 0, close_mlx_win, &data);
	mlx_loop(data.mlx);
}

initialization(t_vars *data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (int)WIDTH, (int)HEIGHT, TITLE);
}
