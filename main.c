/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:18:10 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 21:15:25 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char			*name_of_file;
	int				length;
	int				board_size;
	t_block_point	*block_array;
	int				*memo_max_block;

	board_size = 0;
	name_of_file = argv[1];
	memo_max_block = ft_an_edge_is_all_you_need(name_of_file, board_size,
			memo_max_block);
	ft_display_dict(block_array, board_size);
	return (0);
}
