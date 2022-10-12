#include "../so_long.h"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_map_name(argv[1]) == 1)
		{
			if (check_file_presence(argv[1]) == 1)
			{
				init_map(argv[1]);
			}
			else
				exit (error("File not present at the location you selected !"));
		}
		else
			exit (error("Extension must be .ber nothing else !"));
	}
	else
		exit (error("Add a file path to a file with type .ber !"));
}
