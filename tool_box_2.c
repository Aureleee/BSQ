/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:52:09 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 02:57:39 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_update_edge_1(int *edge, t_block_point *block_point, int length)
{
	int	index;

	index = length - 1;
	if ((*block_point).visible != -1)
	{
		while (index > -1)
		{
			if (index <= (*block_point).pos_x
				&& edge[index] < (*block_point).pos_y)
				edge[index] = (*block_point).pos_y;
			index--;
		}
		block_point->visible = 0;
	}
}

int	ft_check_square(int pos_y, int pos_x, t_block_point *block_array,
		int board_size)
{
	int	size;
	int	flag_block_found;
	int	turn;

	flag_block_found = 1;
	size = 0;
	turn = 0;
	while (pos_y < board_size && pos_x < board_size && flag_block_found == 1)
	{
		flag_block_found = ft_check_block_1(block_array, &pos_y, &pos_x);
		pos_y++;
		pos_x++;
		size++;
		if (flag_block_found == 2 && turn == 0)
			size = 0;
		turn++;
	}
	if (flag_block_found == 2 && turn != 1)
		size--;
	return (size);
}

int	ft_check_block_1(t_block_point *block_array, int *pos_y, int *pos_x)
{
	int	index;
	int	flag;

	flag = 1;
	index = 0;
	while (block_array[index].visible != -1 && flag == 1)
	{
		if (*pos_y == block_array[index].pos_y
			&& *pos_x == block_array[index].pos_x)
			flag = 2;
		if (*pos_x + 1 == block_array[index].pos_x
			&& *pos_y >= block_array[index].pos_y)
			flag = 0;
		if (*pos_y + 1 == block_array[index].pos_y
			&& *pos_x >= block_array[index].pos_x)
			flag = 0;
		index++;
	}
	return (flag);
}

void    ft_need_a_name(int *edge, t_block_point *block_array, int board_size, int *max_boxe)
{
    int index;
    
    index = 0;
    while (index < board_size -1)
    {
        if (edge[index] != edge[index + 1])
        
    }
    ft_check_square
}
