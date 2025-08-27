/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 02:38:10 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 02:09:52 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_block_point	*ft_malloc_block(char *board, int *number_block,
		int *length_board)
{
	int				fd;
	char			c;
	t_block_point	*block_array;
	int				flag;

	flag = 1;
	*number_block = 0;
	fd = open(board, O_RDONLY);
	while (read(fd, &c, 1) > 0 && c != '\n')
		;
	while (read(fd, &c, 1) > 0)
	{
		if (c == 'o')
			(*number_block)++;
		if (c != '\n' && flag)
			(*length_board)++;
		if (c == '\n')
			flag = 0;
	}
	block_array = malloc((*number_block + 1) * sizeof(t_block_point));
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
	c = 'x';
	pos_y = 0;
	pos_x = 0;
	ft_fill_array_block_1(array_block, &k, &pos_x, &pos_y, c);
	return (array_block);
}

void	ft_fill_array_block_1(t_block_point *array_block, int *k, int *pos_x,
		int *pos_y, char c)
{
	if (c == 'o' || c == 'x')
	{
		array_block[*k].pos_x = *pos_x;
		array_block[*k].pos_y = *pos_y;
		if (c == 'o')
			array_block[*k].visible = 1;
		else
			array_block[*k].visible = -1;
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
