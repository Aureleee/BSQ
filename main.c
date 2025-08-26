/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:18:10 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/26 04:15:18 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char			*name_of_file;
	int				length;
	t_block_point	*block_array;

	name_of_file = argv[1];
	block_array = ft_malloc_block(name_of_file, &length);
	ft_display_dict(block_array, length);
	return (0);
}
