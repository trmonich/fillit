#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>

//comrendre le probleme list to struct


unsigned short	tab_to_shape(char **tab)
{
	unsigned short	shape;
	int		i;
	int		j;
	int		first[2];

	write(1, "on rentre dans topiece\n", 24);
	first[0] = 0;
	first[1] = 0;

	shape = 0;
	i = -1;
	while (tab[++i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		write(1, "\n", 1);
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
			{
				if (!first[0])
					first[0] = i;
				if (!first[1])
					first[1] = j;
				shape = shape & (1 << (16 - (i * 4 + j))); // a revoir, struct pour coordonne du point ?
			}
		}
	}
	write(1, "on a cree la piece\n", 24);
	shape = shape << (first[0] * 4);
	shape = shape << (first[1]);
	return (shape);
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

static int		check_validity(char **tab)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		if (ft_strlen(tab[i]) != 4)
			return (0);
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
				count++;
			else if (tab[i][j] != '.')
				return (0);
		}
	}
	if (i != 4 || count != 4)
		return (0);
	return (1);
}

t_piece *new_piece(unsigned short shape)
{
	static char c = 'A';
	t_piece		*piece;

	piece->shape = shape;
	size(piece);
	return (piece);
}

t_list	*read_pieces(int fd)
{
	char	**tab;
	t_list	*list;
	t_piece	*piece;
	char	buff[BUFF_SIZE + 1]; //mis a 20 + 1, au cas ou la taille changerait
	int		ret;

	list = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = 0;
		tab = ft_strsplit(buff, '\n');
		//deb
		int i = 0;
		while (tab[i])
		{
			ft_putendl(tab[i]);
			i++;
		}
		write(1,"pas la 1\n", 9);
		if (!check_validity(tab))
			return (NULL);
		//piece = to_piece(tab);
		//if (!piece->shape)
		//	return (NULL);
		//	debug
		unsigned short shape = tab_to_shape(tab);
		write(1,"pas la 2\n", 9);
		piece = new_piece(tab_to_shape(tab));
		write(1,"pas la 3\n", 9);
		ft_lstappend(&list, ft_lstnew(piece, sizeof(piece)));
		if (read(fd, buff, 1) && *buff != '\n')
			return (NULL);
	}
	//free le tab
	return (list);
}

int		main()
{
	int		fd;
	t_list	*list;
	unsigned short n;
	t_piece	*piece;

	fd = open("pieces.txt", O_RDONLY);
	list = read_pieces(fd);
	piece = list->content; //gerer la structure ou la liste
	while (list)
	{
		n = piece->shape;
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
