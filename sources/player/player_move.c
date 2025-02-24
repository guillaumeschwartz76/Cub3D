/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:16 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/24 19:07:18 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	calculate_and_validate_move(t_data *data, double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + dir_x * MOVESPEED;
	new_y = data->player.pos_y + dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_forward(t_data *data)
{
	return (calculate_and_validate_move(data,
			data->player.dir_x, data->player.dir_y));
}

int	move_backward(t_data *data)
{
	return (calculate_and_validate_move(data,
			-data->player.dir_x, -data->player.dir_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_forward(data);
	else if (data->player.move_y == -1)
		moved += move_backward(data);
	if (data->player.move_x == -1)
		moved += move_left(data);
	else if (data->player.move_x == 1)
		moved += move_right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}
