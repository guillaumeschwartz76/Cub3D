/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:06:53 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/24 19:06:55 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	ft_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_quit(data);
	else if (key == XK_Left)
		data->player.rotate -= 1;
	else if (key == XK_Right)
		data->player.rotate += 1;
	else if (key == XK_w)
		data->player.move_y = 1;
	else if (key == XK_a)
		data->player.move_x = -1;
	else if (key == XK_s)
		data->player.move_y = -1;
	else if (key == XK_d)
		data->player.move_x = 1;
	return (0);
}

int	ft_key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_quit(data);
	else if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	else if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	else if (key == XK_a && data->player.move_x == -1)
		data->player.move_x = 0;
	else if (key == XK_d && data->player.move_x == 1)
		data->player.move_x = 0;
	else if (key == XK_Left)
		data->player.rotate = 0;
	else if (key == XK_Right)
		data->player.rotate = 0;
	return (0);
}

void	ft_event(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, ft_quit, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, ft_key_release, data);
}
