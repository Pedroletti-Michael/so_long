#include "../so_long.h"

int	print_map(t_data *module)
{
	module->map->row = 0;
	module->coin->amount = 0;
	while (module->map->row < module->map->height)
	{
		module->map->col = 0;
		while (module->map->col < module->map->width)
		{
			if (choose_sprite(module->map->map[module->map->row], module) == 1)
				return (error("It is not possible to find the sprite!"));
			module->map->col++;
		}
		module->map->row++;
	}
	return (0);
}
