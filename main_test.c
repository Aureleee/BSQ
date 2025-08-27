/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:18:10 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 02:20:23 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char			*name_of_file;
	int				length;
	int				board_size;
	t_block_point	*block_array;
    int max_size;

	board_size = 0;
	name_of_file = argv[1];
	block_array = ft_malloc_block(name_of_file,&board_size,  &length);
    max_size = 0;

    ft_display_dict(block_array, board_size);


    //display edge update
    int edge[10] = {5, 5, -1, -1, -1, -1, -1, -1, -1, -1};
    ft_update_edge_1(edge,&block_array[0],length);
    ft_show_edge(edge, length);
    printf("length = %d\n", length);

    max_size =ft_check_square(0, 1, block_array, length);
    printf("max size = %d\n", max_size);
    return (0);
}

