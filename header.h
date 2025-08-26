/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:19:32 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/26 04:42:14 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct s_block_point
{
	int			unseen;
	int			pos_y;
	int			pos_x;
}				t_block_point;

void			ft_display_dict(t_block_point *arr, int length);
void			ft_fill_array_block_1(t_block_point *array_block, int *k,
					int *pos_x, int *pos_y, char c);
t_block_point	*ft_extract_block_1(char *board, t_block_point *array_block);
t_block_point	*ft_malloc_block(char *board, int *length);

#endif