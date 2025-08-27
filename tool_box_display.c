/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:00:53 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 16:24:26 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>

void	ft_show_edge(int *edge, int board_size)
{
	int		index;
	char	c;

	index = 0;
	while (index < board_size)
	{
		if (edge[index] < 0)
		{
			write(1, "-", 1);
			c = (-edge[index]) + '0';
		}
		else 
			c = edge[index] + '0';

		write(1, &c, 1);
		write(1, ", ", 2);
		index++;
	}
	write(1, "\n", 1);
}

void	ft_display_dict(t_block_point *arr, int number_block)
{
	int	i;

	i = 0;
	while (arr[i].visible != -1 && number_block != 0)
	{
		printf("%d:%d:%d\n", arr[i].visible, arr[i].pos_y, arr[i].pos_x);
		i++;
	}
	printf("%d:%d:%d\n", arr[i].visible, arr[i].pos_y, arr[i].pos_x);
}
