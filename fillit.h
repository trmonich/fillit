#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_piece
{
	unsigned short	shape;
	int		wide;
	int		length;
}			t_piece;

typedef struct		s_list
{
	void		*content;
	int		content_size;
}			t_list;

#endif
