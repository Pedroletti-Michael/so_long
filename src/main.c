#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_arg(argv[1]))
		{
			ft_printf("Le fichier passer en parametre ne correspond pas aux \
			attentes du programme ! Assurez-vous que la map est bien au format \
			.ber et qu'elle repond a toutes les attentes");
		}
		else
			start(/**LA FAUT METTRE LES DONNEES**/);
	}
	else
		ft_printf("Veuillez s'il vous plait inserer un fichier de map au format .ber !");
	return (0);
}
