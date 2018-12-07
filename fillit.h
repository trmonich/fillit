#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"


typedef struct		s_piece
{
	unsigned short	shape;
	int		wide;
	int		length;
}			t_piece;

t_piece *new_piece(unsigned short shape);
t_list	*read_pieces(int fd);
int		calcul(t_list *list);
char	*create_map(int size);

#endif
