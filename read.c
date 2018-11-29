#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>

//comrendre le probleme list to struct

t_piece	to_piece(char **tab)
{
	t_piece	piece;
	int		i;
	int		j;
	int		first[2];
	int		count;

	first[0] = 0;
	first[1] = 0;
	count = 0;
	piece.shape = 0;
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
				piece.shape = piece.shape & (1 << (16 - (i * 4 + j))); // a revoir, struct pour coordonne du point ?
				count++;
			}
			else if (tab[i][j] != '.')
			{
				piece.shape = 0;
				return (piece);
			}
		}
	}
	if (count != 4)
	{
		piece.shape = 0;
		return (piece);
	}
	piece.shape = piece.shape << (first[0] * 4);
	piece. shape = piece.shape << (first[1]);
	return (piece);
}

void	size(t_piece *piece)
{
	int				i;
	unsigned long	test;

	test = (*piece).shape;
	i = 0;
	while (test)
	{
		i++;
		test = test << 1;
	}
	(*piece).length = i / 4 + 1;
	(*piece).wide = i % 4 + 1;
	if ((*piece).length + (*piece).wide > 5)
		(*piece).shape = 0;
}

t_list	*read_pieces(int fd)
{
	char	**tab;
	int		i;
	t_list	*list;
	t_piece	piece;

	tab = (char**)malloc(sizeof(*tab) * 4);
	list = NULL;
	i = 0;
	while (get_next_line(fd, &tab[i]))
	{
		if (i == 4)
		{
			if (*(tab[i]) != '\n' || ft_strlen(tab[i]) != 1)
				return (NULL);
			i = -1;
			//ajouter le maillon, NULL si NULL
			piece = to_piece(tab);
			if (!piece.shape)
				return (NULL);
			ft_lstappend(&list, ft_lstnew(piece, sizeof(piece)));
		}
		else
			if (ft_strlen(tab[i]) != 4)
				return (NULL);
		i++;
	}
	return (list);
}

int		main()
{
	int		fd;
	t_list	*list;
	unsigned short n;
	t_piece	piece;

	fd = open("pieces.txt", O_RDONLY);
	list = read_pieces(fd);
	piece = (t_piece)*(list->content); //gerer la structure ou la liste
	while (list)
	{
		n = piece.shape;
		while (n)
		{
			if (n & 1)
				printf("1");
			else
				printf("0");
		n >>= 1;
		}
		printf("\n");
		list = list->next;
	}
	return (0);
}
