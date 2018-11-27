#include "fillit.h"

t_piece	*to_piece(char tab[4][4])
{
	t_piece	piece;
	int	i;
	int	j;

	t_piece->shape = 0b0;
	i = 0;
	while (tab[i][j])
	{
		j = 0;
		if (tab)
	}

}

t_list	*read(int fd)
{
	char	*tab[4];
	int	i;
	t_list	*list;

	i = 0;
	while (get_next_line(fd, &(tab[i])))
	{
		if (i == 4)
		{
			if (*line != '\n' || ft_strlen(line) != 1)
				return (NULL);
			i = 0;
			//ajouter le maillon, NULL si NULL
			break;
		}
		if (ft_strlen(line) != 4)
			return (NULL);
		
		i++;
	}


}
