/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:36:11 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/17 12:42:12 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

# define POOL_SIZE 26

typedef struct		s_piece
{
	unsigned int	shape[4];
	int				wid;
	int				len;
	int				pos;
}					t_piece;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_piece				*read_pieces(int fd);
void				set_bit(unsigned int *tab, int k, int side);
void				clear_bit(unsigned int *tab, int k, int side);
int					test_bit(unsigned int *tab, int k, int side);
t_piece				new_piece(char	**tab);
int					check_validity(char **tab);
int					get_side(t_piece *pool);
unsigned int		*find_solution(t_piece *pool, unsigned int *map,
									int map_size);
int					display(int side, t_piece *pool);

#endif
