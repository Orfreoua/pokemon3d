/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_in_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:09:05 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 20:09:08 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	pos_x_max(t_data *data)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	pos = 0;
	while (data->fole.mapy[y] != NULL)
	{
		x = 0;
		while (data->fole.mapy[y][x] != '\0')
			x++;
		if (x > pos)
			pos = x;
		y++;
	}
	return (pos);
}

int	pos_x_max_int(t_data *data)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	pos = 0;
	while (data->fole.map[y][0] != -1)
	{
		x = 0;
		while (data->fole.map[y][x] != -1)
			x++;
		if (x > pos)
			pos = x;
		y++;
	}
	return (pos);
}

int	create_trgb(t_color rgb)
{
	return (0 << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

void	all_in_struct(t_data *data)
{
	int	y;

	data->file.north = data->fole.textures.north;
	data->file.south = data->fole.textures.south;
	data->file.east = data->fole.textures.east;
	data->file.west = data->fole.textures.west;
	data->file.floor.color = create_trgb(data->fole.floor);
	data->file.ceiling.color = create_trgb(data->fole.ceiling);
	data->player.angle = data->fole.rotate;
	//data->file.map = data->fole.mapy;
	//print_map(data->fole.mapy);
	//printf("all in struct\n");
	data->file.map = bonus_map(data->fole.mapy, &data->fole);/////////
	y = 0;
	while (data->fole.mapy[y] != NULL)
		y++;
	free(data->file.map[y]);
	data->file.map[y] = NULL;
	data->file.size.y = y;
	data->player.pos.x = data->fole.pos_player.x;
	data->player.pos.y = data->fole.pos_player.y;

}
