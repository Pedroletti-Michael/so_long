#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf.h"
# include "../src/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include "libft.h"
# include "key_event.h"

typedef struct s_player {
	int	pos_x;
	int	pos_y;
	int collectibles;
	int max_collectibles;
	int	movement;
}		t_player;


typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_player	player;
}				t_vars;

#endif
