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
int		size_of_side(t_list *list);
char	*create_map(int size);
int		size_of_map(t_list *list);

#endif
