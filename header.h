/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:19:32 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 16:55:43 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct s_block_point
{
	int			visible;
	int			pos_y;
	int			pos_x;
}				t_block_point;

// for parse input
void			ft_display_dict(t_block_point *arr, int length);
void			ft_fill_array_block_1(t_block_point *array_block, int *k,
					int *pos_x, int *pos_y, char c);
t_block_point	*ft_extract_block_1(char *board, t_block_point *array_block);
t_block_point	*ft_malloc_block(char *board, int *length, int *length_board);
// edge
void			ft_update_edge_1(int *edge, t_block_point *block_point,
					int length);

// check for plays
int				ft_check_block_1(t_block_point *block_array, int *pos_y,
					int *pos_x);
int				ft_check_square_1(int pos_y, int pos_x,
					t_block_point *block_array, int board_size);
int			*ft_max_size_given_edge(int *edge, t_block_point *block_array,
					int board_size,int *memo_max_block);
int	*ft_memo_max_block(int pos_y, int pos_x, int max_size, int *memo_max_block);
// display
void			ft_show_edge(int *edge, int length);
#endif