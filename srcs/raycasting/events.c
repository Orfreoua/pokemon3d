/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:26:50 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 23:27:15 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	release_key(int key_code, t_data *data)
{
	if (key_code == ARROW_LEFT)
		data->key.arrow_left = 0;
	else if (key_code == ARROW_RIGHT)
		data->key.arrow_right = 0;
	else if (key_code == UP)
		data->key.up = 0;
	else if (key_code == DOWN)
		data->key.down = 0;
	else if (key_code == LEFT)
		data->key.left = 0;
	if (key_code == RIGHT)
		data->key.right = 0;
	return (EXIT_SUCCESS);
}

int	press_key(int key_code, t_data *data)
{
	//printf("%d\n", key_code);
	if (key_code == ECHAP)
		close_window(data);
	if (key_code == ARROW_LEFT)
		data->key.arrow_left = 1;
	else if (key_code == ARROW_RIGHT)
		data->key.arrow_right = 1;
	else if (key_code == UP)
		data->key.up = 1;
	else if (key_code == DOWN)
		data->key.down = 1;
	else if (key_code == LEFT)
		data->key.left = 1;
	if (key_code == RIGHT)
		data->key.right = 1;
	return (EXIT_SUCCESS);
}

int	close_window(t_data *data)
{
	free_all_nxt(data);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->texture.north.img);
	mlx_destroy_image(data->mlx, data->texture.south.img);
	mlx_destroy_image(data->mlx, data->texture.east.img);
	mlx_destroy_image(data->mlx, data->texture.west.img);
	mlx_destroy_window(data->mlx, data->win);
	//mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
