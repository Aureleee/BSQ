/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 02:38:10 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/26 04:43:14 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_block_point	*ft_malloc_block(char *board, int *length)
{
	int				fd;
	char			c;
	t_block_point	*block_array;

	*length = 0;
	fd = open(board, O_RDONLY);
	while (read(fd, &c, 1) > 0 && c != '\n')
		;
	while (read(fd, &c, 1) > 0)
	{
		if (c == 'o')
			(*length)++;
	}
	block_array = malloc((*length) * sizeof(t_block_point));
	close(fd);
	block_array = ft_extract_block_1(board, block_array);
	return (block_array);
}

t_block_point	*ft_extract_block_1(char *board, t_block_point *array_block)
{
	int		fd;
	char	c;
	int		pos_x;
	int		pos_y;
	int		k;

	pos_y = 0;
	pos_x = 0;
	k = 0;
	fd = open(board, O_RDONLY);
	while (read(fd, &c, 1) > 0 && c != '\n')
		;
	while (read(fd, &c, 1) > 0)
		ft_fill_array_block_1(array_block, &k, &pos_x, &pos_y, c);
	close(fd);
	return (array_block);
}

void	ft_fill_array_block_1(t_block_point *array_block, int *k, int *pos_x,
		int *pos_y, char c)
{
	if (c == 'o')
	{
		array_block[*k].pos_x = *pos_x;
		array_block[*k].pos_y = *pos_y;
		array_block[*k].unseen = 0;
		(*k)++;
		(*pos_x)++;
	}
	else if (c == '\n')
	{
		(*pos_y)++;
		(*pos_x) = 0;
	}
	else
		(*pos_x)++;
}

void	ft_display_dict(t_block_point *arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		printf("%d:%d:%d\n", arr[i].unseen, arr[i].pos_y, arr[i].pos_x);
		i++;
	}
}
