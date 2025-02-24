/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:48 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/24 19:07:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	rotate_direction(t_player *player, double rotspeed)
{
	double	tmp_dir_x;

	tmp_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotspeed)
		- player->dir_y * sin(rotspeed);
	player->dir_y = tmp_dir_x * sin(rotspeed) + player->dir_y * cos(rotspeed);
}

void	rotate_plane(t_player *player, double rotspeed)
{
	double	tmp_plane_x;

	tmp_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotspeed)
		- player->plane_y * sin(rotspeed);
	player->plane_y = tmp_plane_x * sin(rotspeed)
		+ player->plane_y * cos(rotspeed);
}

int	rotate_player(t_data *data, double rotdir)
{
	double	rotspeed;

	if (rotdir == 0)
		return (0);
	rotspeed = ROTSPEED * rotdir;
	rotate_direction(&data->player, rotspeed);
	rotate_plane(&data->player, rotspeed);
	return (1);
}
