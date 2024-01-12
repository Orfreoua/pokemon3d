/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_logique.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:42:33 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 23:59:35 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

double	calculate_distance_x(t_data *data)
{
	float	dist;
	float	fish;

	if (data->ray.ray_cos < 0)
		data->ray.dx++;
	data->ray.dx = floor(data->ray.dx);
	dist = sqrt(pow(data->player.pos.x - data->ray.dx, 2)
			+ pow(data->player.pos.y - data->ray.dy, 2));
	fish = cos(degrees_to_radians(fabs(data->ray.angle - data->player.angle)));
	return (dist * fish);
}

double	calculate_distance_y(t_data *data)
{
	float	dist;
	float	fish;

	if (data->ray.ray_sin < 0)
		data->ray.dy++;
	data->ray.dy = floor(data->ray.dy);
	dist = sqrt(pow(data->player.pos.x - data->ray.dx, 2)
			+ pow(data->player.pos.y - data->ray.dy, 2));
	fish = cos(degrees_to_radians(fabs(data->ray.angle - data->player.angle)));
	return (dist * fish);
}

int	raycasting(t_data *data)
{
	int	i;

	i = 0;
	move(data);
	init_ray(data);
	draw_background(data);
	while (i < R_WIDTH)
	{
		data->ray.last_x = data->player.pos.x;
		data->ray.last_y = data->player.pos.y;
		data->ray.dx = data->player.pos.x;
		data->ray.dy = data->player.pos.y;
		data->ray.ray_cos = cos(degrees_to_radians(data->ray.angle)) / PRECISION;
		data->ray.ray_sin = sin(degrees_to_radians(data->ray.angle)) / PRECISION;
		while (!hit_wall(data, i, 0))
			increment_ray(&data->ray);
		data->ray.angle += FOV / (double)R_WIDTH;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	////juste pour le kiff///
	static int frame = 0;
	static int x = 0;
	static int y = 0;
	static int z = 449;
	y++;
	if (x < 450)
	{
		if (y < 50)
			mlx_put_image_to_window(data->mlx, data->win, data->drago.textures_b[frame++].img, x++, 0);
		else 
			mlx_put_image_to_window(data->mlx, data->win, data->drago.textures_b[frame++].img, x++, 0);
	}
	else if (z > 0)
	{
		if (y < 50)
			mlx_put_image_to_window(data->mlx, data->win, data->drago.textures[frame++].img, z--, 0);
		else 
			mlx_put_image_to_window(data->mlx, data->win, data->drago.textures[frame++].img, z--, 0);
	}
	if (z == 0)
	{
		x = 0;
		z = 450;
	}
	if (y > 100)
		y = 0;
	usleep(10000);
	if (frame == 46)
		frame = 0;
	return (0);
}
