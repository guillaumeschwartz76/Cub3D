/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:05 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/24 19:07:07 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	init_player_north_south(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
}

void	init_player_east_west(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}

void	init_player_direction(t_data *data)
{
	if (data->player.dir == 'N' || data->player.dir == 'S')
		init_player_north_south(&data->player);
	else if (data->player.dir == 'E' || data->player.dir == 'W')
		init_player_east_west(&data->player);
	else
		printf("Error: Invalid player direction '%c'\n", data->player.dir);
}
