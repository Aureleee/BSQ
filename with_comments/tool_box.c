/* int	ft_check_block_1(t_block_point *block_array, int *pos_y, int *pos_x)
{
	int	index;
	int	flag;

	flag = 1;
	index = 0;
	while (block_array[index].visible != -1 && flag == 1)
	{
#include <stdio.h>
		printf("%d:%d:%d\n", block_array[index].visible,
			block_array[index].pos_y, block_array[index].pos_x);
		printf("pos_x; %d, block_x : %d\n", *pos_x ,
			block_array[index].pos_x);
		printf("pos_y ; %d, block_y : %d\n", *pos_y, block_array[index].pos_y);
		if (*pos_y == block_array[index].pos_y
			&& *pos_x == block_array[index].pos_x)
		{
			flag = 2;
			printf("flag x & y\n");
		}
		if (*pos_x + 1 == block_array[index].pos_x
			&& *pos_y >= block_array[index].pos_y)
		{
			flag = 0;
			printf("flag x\n");
		}
		if (*pos_y + 1 == block_array[index].pos_y
			&& *pos_x >= block_array[index].pos_x)
		{
			flag = 0;
			printf("flag y\n");
		}
		index++;
	}
	return (flag);
}
 */
