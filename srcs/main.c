/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:58:16 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/29 00:42:16 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	exit_mlx(t_data *data, char *msg_error, int step)
{
	free_all_nxt(data);
	if (step > 0)
		mlx_destroy_window(data->mlx, data->win);
	if (step > 1)
		mlx_destroy_image(data->mlx, data->img.img);
	if (step > 2)
		mlx_destroy_image(data->mlx, data->texture.north.img);
	if (step > 3)
		mlx_destroy_image(data->mlx, data->texture.south.img);
	if (step > 4)
		mlx_destroy_image(data->mlx, data->texture.east.img);
	if (step > 5)
		mlx_destroy_image(data->mlx, data->texture.west.img);
	//mlx_destroy_display(data->mlx);
	free(data->mlx);
	print_error(msg_error);
	exit(1);
}

void	game_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &raycasting, data);
	mlx_hook(data->win, 2, 1L << 0, &press_key, data);
	mlx_hook(data->win, 3, 1L << 1, &release_key, data);
	if (!OS)
		mlx_hook(data->win, 33, 1L << 5, close_window, data);
	else
		mlx_hook(data->win, 17, 0, close_window, data);
}

int	main(int argc, char **argv)
{
	t_data	data;
data.bonus = 0;
	if (argc != 2)
		return (print_error(BAD_NB_ARG));
	if (load_fole(&data, argv[1]) == ERROR)
		return (EXIT_FAILLURE);
	all_in_struct(&data);
//	print_map(data.file.map);	exit(0);
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(print_error(MLX_CONNECTION));
	data.win = mlx_new_window(data.mlx, R_WIDTH, R_HEIGHT, "");
	if (!data.win)
		exit_mlx(&data, WIN_CONNECTION, 0);
	data.img.img = mlx_new_image(data.mlx, R_WIDTH, R_HEIGHT);
	if (!data.img.img)
		exit_mlx(&data, IMG_CREATE, 1);
	data.img.addr = (char *)mlx_get_data_addr(data.img.img, &data.img.bpp,
			&data.img.size_line, &data.img.endian);
	setting(&data);
	game_loop(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
