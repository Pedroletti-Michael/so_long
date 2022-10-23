#include "../so_long.h"

int	main(int argc, char **argv)
{
	int	value;

	value = 0;
	if (argc == 2)
	{
		if (check_map_name(argv[1]) == 1)
		{
			if (check_file_presence(argv[1]) == 1)
			{
				value = init_map(argv[1]);
			}
			else
				value = 9;
		}
		else
			value = 10;
	}
	else
		value = 11;
	exit (ft_printf(error_handler(value)));
}
