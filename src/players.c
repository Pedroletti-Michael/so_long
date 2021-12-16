#include "../includes/so_long.h"

void	player_move(int keycode, t_vars *data)
{
	if (keycode == W)
		move_forward(data);
	if (keycode == S)
		move_backward(data);
	if (keycode == A)
		move_left(data);
	if (keycode == D)
		move_right(data);
}

// Maybe we can use one only function to move, because if we just give the direction on which we want to move, we don't need to make 4 functions

void	move_forward()
{
	// make the player move forward
}

void	move_backward()
{
	// make the player move backward
}

void	move_left()
{
	// make the player move on the left
}

void	move_right()
{
	// make the player move on the right
}
