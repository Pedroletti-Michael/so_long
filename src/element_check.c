#include "../includes/so_long.h"

int	check_empty_space(t_vars *data, int direction)
{
	// check if we have an empty space in the direction of the next case that's the player choose to go. If it's true he can go, else we need to check other parameters
}

int	check_collectible(t_vars *data, int direction)
{
	// check if the player stand on a case with a collectible, if it's true count that's the player get the collectible and replace the case by an empty case
}

int	check_exit(t_vars *data, int direction)
{
	// check if an exit case is in the next direction case if it's true we need to check if we get all collectibles of the map before exit
}

int	check_wall(t_vars *data, int direction)
{
	// check if the player next direction case is a wall, if it's true, we count a move but we don't move the player because they're a wall in the next case
}

