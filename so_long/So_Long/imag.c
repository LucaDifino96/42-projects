/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:08:58 by ldifino           #+#    #+#             */
/*   Updated: 2023/08/09 17:24:51 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img02(int i, int j, t_all *box)
{
	if (box->map.mapm[i][j] == 'E')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->imag.exit, j * 64, (i + 1) * 64);
	else if (box->map.mapm[i][j] == 'C')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->imag.collectible, j * 64, (i + 1) * 64);
	else if (box->map.mapm[i][j] == 'N')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->imag.enemy, j * 64, (i + 1) * 64);
	else if (box->map.mapm[i][j] == 'P')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->imag.current_player, j * 64, (i + 1) * 64);
}

void	put_img01(t_all *box)
{
	int	i;
	int	j;

	i = -1;
	while (box->map.mapm[++i])
	{
		j = -1;
		while (box->map.mapm[i][++j])
		{
			if (box->map.mapm[i][j] == '1')
				mlx_put_image_to_window(box->map.mlx, box->map.window,
					box->imag.wall, j * 64, (i + 1) * 64);
			else if (box->map.mapm[i][j] == '0')
				mlx_put_image_to_window(box->map.mlx, box->map.window,
					box->imag.floor, j * 64, (i + 1) * 64);
			else if (box->map.mapm[i][j] == 'E' || box->map.mapm[i][j] == 'C'
				|| box->map.mapm[i][j] == 'N' || box->map.mapm[i][j] == 'P')
				put_img02(i, j, box);
		}
	}
}

int	enemy_patrol(t_all *box)
{
	if (box->moves.patrol < 7000)
	{
		box->moves.patrol++;
		return (0);
	}
	box->moves.patrol = 0;
	if (box->imag.patrol_flag == 1)
		box->imag.enemy = mlx_xpm_file_to_image(box->map.mlx,
				"./imag/enemyl.xpm", &box->imag.size_img,
				&box->imag.size_img);
	else
	{
		box->imag.enemy = mlx_xpm_file_to_image(box->map.mlx,
				"./imag/enemyr.xpm", &box->imag.size_img,
				&box->imag.size_img);
		box->imag.patrol_flag = 0;
	}
	put_img01(box);
	box->imag.patrol_flag++;
	return (0);
}
