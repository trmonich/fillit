#include "fillit.h"

t_piece	to_piece(char (*tab)[4])
{
	t_piece	piece;
	int		i;
	int		j;
	int		first[2];
	int		count;

	first_line = 0;
	first_col = 0;
	count = 0;
	piece->shape = 0;
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
			{
				if (!first[0])
					first[0] = i;
				if (!first[1])
					first[1] = j;
				piece->shape & (1 << (i * 4 + j + 1)); // a revoir, struct pour coordonne du point ?
				count++;
			}
			else if (tab[i][j] != '.')
			{
				piece->shape = 0;
				return (piece);
			}
		}
	}
	if (count != 4)
	{
		piece->shape = 0;
		return (piece);
	}
	piece->shape << (first[0] * 4);
	piece->shape << (first[1]);
	return (piece);
}

void	*size(t_piece *piece)
{
	int				i;
	unsigned long	test;

	test = (*piece)->shape;
	i = 0;
	while (test)
	{
		i++;
		test << 1;
	}
	piece->length = i / 4 + 1;
	piece->wide = i % 4 + 1;
	if (length + wide > 5)
		piece->shape = 0;
}

t_list	*read(int fd)
{
	char	(*tab)[4];
	int	i;
	t_list	*list;

	i = 0;
	while (get_next_line(fd, tab[i]))
	{
		if (i == 4)
		{
			if (*line != '\n' || ft_strlen(line) != 1)
				return (NULL);
			i = -1;
			//ajouter le maillon, NULL si NULL
		}
		else
			if (ft_strlen(line) != 4)
				return (NULL);
		i++;
	}


}
