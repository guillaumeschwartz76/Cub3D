/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:05:40 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/24 19:05:42 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	init_img(t_data *data, t_img *image, int width, int height)
{
	image->img = mlx_new_image(data->mlx, width, height);
	if (!image->img)
		clean_exit(data, 1);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.size,
			&data->texinfo.size);
	if (!image->img)
		clean_exit(data, 2);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, 3);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		clean_exit(data, 4);
}
