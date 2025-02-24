/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:37 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/24 19:07:38 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

bool	is_within_map_bounds(t_data *data, double x, double y)
{
	return (x >= 0.25 && x < data->mapinfo.width - 1.25
		&& y >= 0.25 && y < data->mapinfo.height - 0.25);
}

bool	is_not_wall(t_data *data, double x, double y)
{
	return (data->map[(int)y][(int)x] == '0');
}

bool	is_valid_position(t_data *data, double x, double y)
{
	if (!is_within_map_bounds(data, x, y))
		return (false);
	if (!is_not_wall(data, x, y))
		return (false);
	return (true);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_position(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_position(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
