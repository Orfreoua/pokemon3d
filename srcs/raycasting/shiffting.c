/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiffting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:43:04 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 13:28:35 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	is_walkable(const t_data *data, double x, double y)
{
	if (data->file.map[(int)y][(int)x] != '0' ||
		data->file.map[(int)y][(int)(x - WALL_GAP)] != '0' ||
		data->file.map[(int)y][(int)(x + WALL_GAP)] != '0' ||
		data->file.map[(int)(y - WALL_GAP)][(int)x] != '0' ||
		data->file.map[(int)(y + WALL_GAP)][(int)x] != '0')
		return (0);
	return (1);
}

void	shiffting_arrow(t_data *data)
{
	if (data->key.arrow_left)
	{
		data->player.angle -= ROT_SP;
		if (data->player.angle == -1)
			data->player.angle = 360;
		return ;
	}
	data->player.angle += ROT_SP;
	if (data->player.angle == 361)
		data->player.angle = 0;
}

void	shiffting(t_data *data, double cos, double sin, double speed)
{
	double	x;
	double	y;

	x = data->player.pos.x + cos / speed;
	y = data->player.pos.y + sin / speed;
	if (is_walkable(data, x, y))
	{
		data->player.pos.x = x;
		data->player.pos.y = y;
	}
}

void	move(t_data *data)
{
	if (data->key.arrow_left || data->key.arrow_right)
		shiffting_arrow(data);
	if (data->key.up)
		shiffting(data, cos(degrees_to_radians(data->player.angle)),
			sin(degrees_to_radians(data->player.angle)), RUN_SP);
	if (data->key.down)
		shiffting(data, -cos(degrees_to_radians(data->player.angle)),
			-sin(degrees_to_radians(data->player.angle)), RUN_SP);
	if (data->key.left)
		shiffting(data, cos(degrees_to_radians(data->player.angle - 90)),
			sin(degrees_to_radians(data->player.angle - 90)), SIDE_SP);
	if (data->key.right)
		shiffting(data, cos(degrees_to_radians(data->player.angle + 90)),
			sin(degrees_to_radians(data->player.angle + 90)), SIDE_SP);
}
