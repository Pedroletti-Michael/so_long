#include "../so_long.h"


/*
Transférer le t_data dans une autre fonction et faire
le plus de test possible dans main sans le t_data.
Puis faire attention à ce qu'il n'y ai plus de segmentation fault
télécharger brew et valgrind
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = malloc(1 * sizeof(t_data));
		if (data == NULL)
			exit(error("Allocation memory error !"));
		if (check_map(argv[1], data) == 0)
		{
			start_game(data);
			hook(data);
			mlx_loop(data->vars->mlx);
		}
		else
		{
			clear_map(data->map);
			free_ptr((void **)&data);
			exit(-1);
		}
	}
	else
		exit (error("Add a file path to a file with type .ber !"));
}
