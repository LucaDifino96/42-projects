/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:00:27 by ldifino           #+#    #+#             */
/*   Updated: 2023/08/09 17:25:06 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <signal.h>

void	free_memory(t_all *box)
{
	int	i;

	i = 0;
	while (box->map.mapm[i])
	{
		free(box->map.mapm[i]);
		i++;
	}
	free(box->map.mapm);
	mlx_destroy_image(box->map.mlx, box->imag.starr);
	mlx_destroy_image(box->map.mlx, box->imag.starl);
	mlx_destroy_image(box->map.mlx, box->imag.enemy);
	mlx_destroy_image(box->map.mlx, box->imag.collectible);
	mlx_destroy_image(box->map.mlx, box->imag.wall);
	mlx_destroy_image(box->map.mlx, box->imag.exit);
	mlx_destroy_image(box->map.mlx, box->imag.floor);
	free(box->map.mlx);
	free(box->map.mapv);
	exit(0);
}

static void	utils(t_all *box)
{
	box->imag.size_img = 64;
	box->imag.victory_obj = 0;
	box->moves.counter = 1;
	box->imag.patrol_flag = 1;
}

void	print_counter(t_all *box)
{
	box->imag.display_moves = ft_itoa(box->moves.counter);
	mlx_string_put(box->map.mlx, box->map.window, 20, 30, 0xFFFFFF, "MOVES : ");
	mlx_string_put(box->map.mlx, box->map.window, 100, 30, 0xFFFFFF,
		box->imag.display_moves);
	box->moves.counter++;
	free(box->imag.display_moves);
}

int	main(int ac, char **av)
{
	t_all	box;

	if (ac != 2)
	{
		ft_printf("Error\n%s\n", strerror(EINVAL));
		exit (1);
	}
	utils(&box);
	check_argv(av[1]);
	read_map(av[1], &box);
	player_position(&box);
	check_rect(&box);
	check_let01(&box);
	check_let02(&box);
	check_wall(&box);
	free(box.map.mapv);
	window(&box);
	take_img(&box);
	box.imag.current_player = box.imag.starr;
	put_img01(&box);
	mlx_key_hook(box.map.window, key_input, &box);
	mlx_loop_hook(box.map.mlx, enemy_patrol, &box);
	mlx_loop(box.map.mlx);
	free_memory(&box);
	return (0);
}
