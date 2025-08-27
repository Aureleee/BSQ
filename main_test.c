/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:18:10 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 16:58:30 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char			*name_of_file;
	int				number_block;
	int				board_size;
	t_block_point	*block_array;
    int *memo_max_block;

    memo_max_block = malloc(3*sizeof(int));
	board_size = 0;
	name_of_file = argv[1];
	block_array = ft_malloc_block(name_of_file, &number_block, &board_size);
    ft_display_dict(block_array, board_size);


    //display edge update
    int edge[10] = {6, 6,6 ,6, 1, 0, 0, 0, 0, -1};
    ft_show_edge(edge, board_size);
    //ft_update_edge_1(edge,&block_array[0],number_block);
    printf("length = %d\n", board_size);

    memo_max_block =ft_max_size_given_edge(edge,block_array,board_size, memo_max_block);
    printf("max boxe = %d , pos_y = %d , pos_x = %d\n", memo_max_block[0], memo_max_block[1], memo_max_block[2]);
    return (0);
}

