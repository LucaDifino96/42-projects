/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:09:05 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/16 14:28:20 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	quit(void)
{
	exit(0);
}

void	window(t_all *box)
{
	int		i;

	i = 0;
	while (box->map.mapm[i])
		i++;
	box->map.mlx = mlx_init();
	box->map.window = mlx_new_window(box->map.mlx,
			(64 * ft_strlen(box->map.mapm[0])), (64 * (i) + 64), "so_long");
	mlx_hook(box->map.window, 17, 0, quit, 0);
}

void	take_img(t_all *box)
{
	box->imag.starr = mlx_xpm_file_to_image(box->map.mlx, "./imag/starr.xpm",
			&box->imag.size_img, &box->imag.size_img);
	box->imag.starl = mlx_xpm_file_to_image(box->map.mlx, "./imag/starl.xpm",
			&box->imag.size_img, &box->imag.size_img);
	box->imag.enemy = mlx_xpm_file_to_image(box->map.mlx, "./imag/enemyr.xpm",
			&box->imag.size_img, &box->imag.size_img);
	box->imag.collectible = mlx_xpm_file_to_image \
	(box->map.mlx, "./imag/collectible.xpm", \
			&box->imag.size_img, &box->imag.size_img);
	box->imag.floor = mlx_xpm_file_to_image(box->map.mlx, "./imag/floor.xpm",
			&box->imag.size_img, &box->imag.size_img);
	box->imag.exit = mlx_xpm_file_to_image(box->map.mlx, "./imag/doorc.xpm",
			&box->imag.size_img, &box->imag.size_img);
	box->imag.wall = mlx_xpm_file_to_image(box->map.mlx, "./imag/wall.xpm",
			&box->imag.size_img, &box->imag.size_img);
}
