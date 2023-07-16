/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:09:11 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/16 14:27:24 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i - 1][box->moves.j] == '0' ||
		box->map.mapm[box->moves.i - 1][box->moves.j] == 'C')
	{
		if (box->map.mapm[box->moves.i - 1][box->moves.j] == 'C')
		{
			box->imag.victory_obj--;
			if (box->imag.victory_obj == 0)
				box->imag.exit = mlx_xpm_file_to_image(box->map.mlx, \
				"./imag/dooro.xpm", &box->imag.size_img, &box->imag.size_img);
		}
		box->map.mapm[box->moves.i - 1][box->moves.j] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i - 1][box->moves.j] == 'E')
	{
		if (box->imag.victory_obj == 0)
			exit(0);
	}
	else if (box->map.mapm[box->moves.i - 1][box->moves.j] == 'N')
		exit(0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

void	move_down(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i + 1][box->moves.j] == '0' ||
		box->map.mapm[box->moves.i + 1][box->moves.j] == 'C')
	{
		if (box->map.mapm[box->moves.i + 1][box->moves.j] == 'C')
		{
			box->imag.victory_obj--;
			if (box->imag.victory_obj == 0)
				box->imag.exit = mlx_xpm_file_to_image(box->map.mlx, \
				"./imag/dooro.xpm", &box->imag.size_img, &box->imag.size_img);
		}
		box->map.mapm[box->moves.i + 1][box->moves.j] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i + 1][box->moves.j] == 'E')
	{
		if (box->imag.victory_obj == 0)
			exit(0);
	}
	else if (box->map.mapm[box->moves.i + 1][box->moves.j] == 'N')
		exit(0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

void	move_left(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i][box->moves.j - 1] == '0' ||
		box->map.mapm[box->moves.i][box->moves.j - 1] == 'C')
	{
		if (box->map.mapm[box->moves.i][box->moves.j - 1] == 'C')
		{
			box->imag.victory_obj--;
			if (box->imag.victory_obj == 0)
				box->imag.exit = mlx_xpm_file_to_image(box->map.mlx, \
				"./imag/dooro.xpm", &box->imag.size_img, &box->imag.size_img);
		}
		box->map.mapm[box->moves.i][box->moves.j - 1] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i][box->moves.j - 1] == 'E')
	{
		if (box->imag.victory_obj == 0)
			exit(0);
	}
	else if (box->map.mapm[box->moves.i][box->moves.j - 1] == 'N')
		exit(0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

void	move_right(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i][box->moves.j + 1] == '0' ||
		box->map.mapm[box->moves.i][box->moves.j + 1] == 'C')
	{
		if (box->map.mapm[box->moves.i][box->moves.j + 1] == 'C')
		{
			box->imag.victory_obj--;
			if (box->imag.victory_obj == 0)
				box->imag.exit = mlx_xpm_file_to_image(box->map.mlx, \
				"./imag/dooro.xpm", &box->imag.size_img, &box->imag.size_img);
		}
		box->map.mapm[box->moves.i][box->moves.j + 1] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i][box->moves.j + 1] == 'E')
	{
		if (box->imag.victory_obj == 0)
			exit(0);
	}
	else if (box->map.mapm[box->moves.i][box->moves.j + 1] == 'N')
		exit(0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

int	key_input(int k, t_all *box)
{
	if (k == 13 || k == 126)
	{
		move_up(box);
	}
	else if (k == 1 || k == 125)
	{
		move_down(box);
	}
	else if (k == 2 || k == 124)
	{
		box->imag.current_player = box->imag.starr;
		move_right(box);
	}
	else if (k == 0 || k == 123)
	{	
		box->imag.current_player = box->imag.starl;
		move_left(box);
	}
	else if (k == 53)
	{
		free_memory(box);
		exit(0);
	}
	return (0);
}
