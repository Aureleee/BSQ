/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:52:09 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 20:37:35 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_update_edge(int *edge, t_block_point *block_array, int board_size,
		int number_block)
{
	int	index_board;
	int	index_block;

	index_board = board_size - 1;
	index_block = 0;
	if ((*block_array).visible != -1)
	{
		while (index_block < board_size
			&& block_array[index_block].visible == 0)
		{
			printf("block visible : %d", block_array[index_block].visible);
			while (index_board > -1)
			{
				if (index_board <= block_array[index_block].pos_x
					&& edge[index_board] < block_array[index_block].pos_y)
					edge[index_board] = block_array[index_block].pos_y;
				index_board--;
			}
			index_block++;
			block_array->visible = 0;
		}
	}
}

int	ft_check_square_1(int pos_y, int pos_x, t_block_point *block_array,
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

int	*ft_max_size_given_edge(int *edge, t_block_point *block_array,
		int board_size, int *memo_max_block)
{
	int	index;
	int	size;

	index = 0;
	size = 0;
	size = ft_check_square_1(edge[0] + 1, 0, block_array, board_size);
	if (size > memo_max_block[0])
		memo_max_block = ft_memo_max_block(edge[0] + 1, 0, size,
				memo_max_block);
	while (index < board_size - 1)
	{
		if (edge[index] != edge[index + 1])
		{
			size = ft_check_square_1(edge[index + 1] + 1, index + 1,
					block_array, board_size);
			printf("pos_y = %d, pos_x = %d, size = %d\n", edge[index + 1] + 1,
				index + 1, size);
		}
		if (size > memo_max_block[0])
			memo_max_block = ft_memo_max_block(edge[index + 1] + 1, index + 1,
					size, memo_max_block);
		index++;
	}
	return (memo_max_block);
}

int	*ft_memo_max_block(int pos_y, int pos_x, int max_size, int *memo_max_block)
{
	memo_max_block[0] = max_size;
	memo_max_block[1] = pos_y;
	memo_max_block[2] = pos_x;
	return (memo_max_block);
}
