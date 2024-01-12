/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:48:41 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 14:54:44 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	within_map_bounds(t_data *data, int dy, int dx)
{
	int	map_height;
	int	map_width;

	map_height = (int)data->file.size.y;
	map_width = (int)ft_strlen(data->file.map[dy]);
	return (dy >= 0 && dy < map_height && dx >= 0 && dx < map_width);
}

void	handle_horizontal_impact(t_data *data, int i)
{
	int index;

	if (!data->bonus)
		index = 0;
	else
		index = (data->file.map[(int)data->ray.dy][(int)data->ray.dx]) - 48;
	data->ray.last_x = data->ray.dx;
	if ((int)data->ray.last_y - (int)data->ray.dy)
		data->text = choose_texture(data, index);
	else
	{
		if (data->ray.dx - data->player.pos.x > 0)
			data->text = data->tab_textures[index].east;
		else
			data->text = data->tab_textures[index].west;
	}
	draw_wall(data, i, calculate_distance_x(data), data->text);
}

void	handle_vertical_impact(t_data *data, int i)
{
	int index;

	if (!data->bonus)
		index = 0;
	else
		index = (data->file.map[(int)data->ray.dy][(int)data->ray.dx]) - 48;
	data->ray.last_x = data->ray.dx;
	data->ray.last_y = data->ray.dy;
	if ((int)data->ray.last_x - (int)data->ray.dx)
		data->text = choose_texture(data, index);
	else
	{
		if (data->ray.dy - data->player.pos.y > 0)
			data->text = data->tab_textures[index].south;
		else
			data->text = data->tab_textures[index].north;
		data->ray.last_y = data->ray.dy;
	}
	draw_wall(data, i, calculate_distance_y(data), data->text);
}

int	hit_wall(t_data *data, int i, int map_width)
{
	map_width = (int)ft_strlen(data->file.map[(int)data->ray.dy]);
	if (within_map_bounds(data, (int)data->ray.dy, (int)data->ray.dx)
		&& (int)data->ray.last_x - (int)data->ray.dx
		&& (int)data->ray.dx < map_width)
	{
		data->ray.last_x = data->ray.dx;
		if (data->file.map[(int)data->ray.dy][(int)data->ray.dx] != '0')
		{
			handle_horizontal_impact(data, i);
			return (1);
		}
	}
	else if (within_map_bounds(data, (int)data->ray.dy, (int)data->ray.dx)
		&& (int)data->ray.last_y - (int)data->ray.dy
		&& (int)data->ray.dx < map_width)
	{
		data->ray.last_y = data->ray.dy;
		if (data->file.map[(int)data->ray.dy][(int)data->ray.dx] != '0')
		{
			handle_vertical_impact(data, i);
			return (1);
		}
	}
	return (0);
}
