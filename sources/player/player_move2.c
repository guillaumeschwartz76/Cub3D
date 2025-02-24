/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:26 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/24 19:07:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	move_left(t_data *data)
{
	return (calculate_and_validate_move(data,
			data->player.dir_y, -data->player.dir_x));
}

int	move_right(t_data *data)
{
	return (calculate_and_validate_move(data,
			-data->player.dir_y, data->player.dir_x));
}
