#include "../so_long.h"

static int	verify_move(t_data *module, char verify)
{
	if (verify == '0')
		return (0);
	if (verify == '1')
		return (1);
	if (verify == 'C')
	{
		module->coin->amount_taken = module->coin->amount_taken + 1;
		return (0);
	}
	if (verify == 'E')
	{
		if (module->coin->amount == 0)
			return (2);
		else
			return (1);
	}
	else
		return (3);
}

void	move(t_data *module, int x, int y, int eye)
{
	int		res;

	res = verify_move(module, module->map->map[y][x]);
	if (res == 0)
	{
		module->player->player_step = module->player->player_step + 1;
		module->player->player_eye = eye;
		module->map->map[y][x] = 'P';
		module->map->map[module->player->player_y]
		[module->player->player_x] = '0';
		print_map(module);
	}
	else if (res == 1)
		module->player->player_eye = eye;
	else if (res == 2)
	{
		ft_printf("\033[32mYOU WIN!\n\033[0");
		module->end_game = 1;
	}
	else if (res == 3)
	{
		ft_printf("\033[31mGAME OVER!\n\033[0");
		module->end_game = 1;
	}
}
