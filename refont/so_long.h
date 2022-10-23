#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./42-printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

# define GROUND "./assets/sprites/0.xpm"
# define WALL "./assets/sprites/1.xpm"
# define COLLECT "./assets/sprites/C.xpm"
# define EXIT "./assets/sprites/E.xpm"
# define PLAYER_1 "./assets/sprites/P_0.xpm"
# define PLAYER_2 "./assets/sprites/P_1.xpm"
# define PLAYER_3 "./assets/sprites/P_2.xpm"
# define PLAYER_4 "./assets/sprites/P_3.xpm"
# define ENEMY_1 "./assets/sprites/J_0.xpm"
# define ENEMY_2 "./assets/sprites/J_1.xpm"
# define ENEMY_3 "./assets/sprites/J_2.xpm"
# define ENEMY_4 "./assets/sprites/J_3.xpm"
# define SPRITE_SIZE 32

# define KEY_ESC 53

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_map
{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		col;
	int		row;
}	t_map;

typedef struct s_objects
{
	int		p;
	int		c;
	int		e;
}			t_objects;

typedef struct s_sprite
{
	void	*wall;
	void	*ground;
	void	*collect;
	void	*exit;
	void	**enemies;
	void	**player;
	int		img_width;
	int		img_height;
}			t_sprite;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_coin
{
	int		amount;
	int		amount_taken;
}			t_coin;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	int		player_eye;
	int		player_step;
}			t_player;

typedef struct s_module
{
	t_vars		*vars;
	t_map		*map;
	t_player	*player;
	t_coin		*coin;
	t_sprite	*sprite;
	int			end_game;
}			t_data;

int		main(int argc, char **argv);
int		check_map_name(char *name);
int		check_file_presence(char *path);
int		init_map(char *path);
int		start(t_data *module);
int		check_map(t_data *data);
int		print_map(t_data *module);
int		choose_sprite(char *line, t_data *module);
void	free_ptr(void **ptr);
int		ft_verify_str(char *str, char *ver, int max_search);
void	init_objects(t_objects *objects);
int		ft_verify_objects(char *line, char object);
int		close_all(t_data *module);
void	close_window(t_data *module);
void	clear_map(t_map *map);
void	move(t_data *module, int x, int y, int eye);

char*	error_handler(int value);

#endif
