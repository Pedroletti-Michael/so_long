#include "../includes/so_long.h"

int	file_name_check(char *name)
{
	int		len;
	int		i;
	char	*format = ".ber";
	int		j;

	len = ft_strlen(name);
	i = len - 5;
	j = 0;
	while (i < len || name[i] == '\0')
	{
		if (name[i] != format[j])
		{
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}

int	check_map(char *map)
{
	// Utilisation de get_next_line nécessaire
	// Checker si la map est entourée de mur
	// Checker si la map contient au minimum un endroit de spawn (P)
	// Checker si la map contient au minimum un objet (C)
	// Checker si la map contient au minimum une sortie (E)
	// (1) == Wall // (0) == Space
	// La map doit etre rectangulaire
}

int	check_arg(char *arg)
{
	if (file_name_check(arg))
	{
		if (check_map(arg))
			return (1);
		else
			return (0);
	}
	else
		return (0);
	// Creation dune fonction qui check la fin du nom du fichier afin de verifier qu'il y a bel est bien un .ber
	// Creation dune fonction qui verifie que la map est bel et bien fonctionnel (correspond a toutes les attentes)
}
