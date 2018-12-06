#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> //debug

//comrendre le probleme list to struct


unsigned short	tab_to_shape(char **tab)
{
	unsigned short	shape;
	int		i;
	int		j;
	int		first[2];

	write(1, "on rentre dans topiece\n", 24);
	first[0] = 3;
	first[1] = 3;

	shape = 0b0;
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
				if (first[0] > i)
					first[0] = i;
				if (first[1] > j)
					first[1] = j;
				shape = shape | (1 << (15 - (i * 4 + j))); // a revoir, struct pour coordonne du point ?
			}
		}
	}
	write(1, "on a cree la piece\n", 24);
	shape = shape << (first[0] * 4);
	shape = shape << (first[1]);
	return (shape);
}

static int		check_validity(char **tab)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		write(1,"pas la val\n", 11);
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
		i++;
	}
	write(1,"pas la sor\n", 11);
	ft_putnbr(i);
	ft_putnbr(count);
	if (i != 4 || count != 4)
		return (0);
	write(1,"pas la po1\n", 11);
	return (1);
}

t_list	*read_pieces(int fd)
{
	char	**tab;
	t_list	*list;
	t_list	*list2;
	t_piece	*piece;
	char	buff[BUFF_SIZE + 1]; //mis a 20 + 1, au cas ou la taille changerait
	int		ret;

	list = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		ft_putstr("test : ");
		ft_putnbr(ret);
		ft_putchar(10);
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
		write(1,"pas la 2\n", 9);
		piece = new_piece(tab_to_shape(tab));
		printf("on a bien %d et %d en sortant encore\n", piece->length, piece->wide);
		write(1,"pas la 3\n", 9);
		list2 = ft_lstnew(piece, sizeof(*piece));
		piece = list2->content;
		printf("on a bien %d et %d en liste\n", piece->length, piece->wide);
		write(1,"pas la 3.5\n", 11);
		ft_lstappend(&list, list2);
		write(1,"pas la 4\n", 9);
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
	t_piece	*piece;

	fd = open("pieces.txt", O_RDONLY);
	list = read_pieces(fd);
	ft_putendl("retour au main");
	printf("taille max = %d\n", calcul(list)); //tests - debug
	while (list)
	{
		piece = (list->content); //gerer la structure ou la liste
		printf("on a bien %d et %d en sortant pour la derniere\n", piece->length, piece->wide);
		ft_putnbr((int)piece->shape);
		ft_putchar(10);
		ft_putnbr((int)piece->wide);
		ft_putchar(10);
		ft_putnbr((int)piece->length);
		ft_putchar(10);
		list = list->next;
	}
	return (0);
}
