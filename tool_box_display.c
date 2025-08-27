/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:00:53 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 02:11:53 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>

void	ft_show_edge(int *edge, int length)
{
	int		index;
	char	c;

	index = 0;
	while (index < length)
	{
		if (edge[index] < 0)
		{
			write(1, "-", 1);
			edge[index] *= -1;
		}
		c = edge[index++] + '0';
		write(1, &c, 1);
		write(1, ", ", 2);
	}
}

void	ft_display_dict(t_block_point *arr, int length)
{
	int	i;

	i = 0;
	while (arr[i].visible != -1 && length != 0)
	{
		printf("%d:%d:%d\n", arr[i].visible, arr[i].pos_y, arr[i].pos_x);
		i++;
	}
	printf("%d:%d:%d\n", arr[i].visible, arr[i].pos_y, arr[i].pos_x);
}
