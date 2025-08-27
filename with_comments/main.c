/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:18:10 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/27 02:12:06 by ahabbard         ###   ########.fr       */
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

	board_size = 0;
	name_of_file = argv[1];
	block_array = ft_malloc_block(name_of_file, &board_size, &length);
	ft_display_dict(block_array, board_size);
	return (0);
}
