/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:28:37 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 21:05:45 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_an_edge_is_all_you_need(char *name_of_file, int board_size,
		int *memo_max_block)
{
	int				*edge;
	int				index;
	int				*number_block;
	t_block_point	*block_array;
	int				flag;

	index = 0;
	edge = ft_init_edge(board_size);
	memo_max_block = malloc(3 * sizeof(int));
	block_array = ft_malloc_block(name_of_file, number_block, &board_size);
	flag = 1;
	while (flag)
	{
		ft_max_size_given_edge(edge, block_array, board_size, memo_max_block);
		ft_update_edge(edge, block_array, board_size, *number_block);
		flag = ft_check_if_finished(edge, memo_max_block, board_size);
	}
	return (memo_max_block);
}

int	*ft_init_edge(int board_size)
{
	int	*edge;
	int	index;

	index = 0;
	edge = malloc((board_size + 1) * sizeof(int));
	while (index < board_size)
	{
		edge[index] = -1;
		index++;
	}
	return (edge);
}

int	ft_check_if_finished(int *edge, int *memo_max_block, int board_size)
{
	int	index;
	int	flag_is_finished;
	int	outer_edge;

	flag_is_finished = 1;
	index = 0;
	outer_edge = board_size - memo_max_block[0];
	while (index < board_size && flag_is_finished)
	{
		if (edge[index] < outer_edge && index < outer_edge)
			flag_is_finished = 0;
		index++;
	}
	return (outer_edge);
}
