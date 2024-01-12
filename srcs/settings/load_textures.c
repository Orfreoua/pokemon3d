#include "headers.h"

int	load_texture(t_data *data, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(data->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		return (1);
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->data)
	{
		mlx_destroy_image(data->mlx, texture->img);
		return (1);
	}
	return (0);
}

void    load_wall(t_data *data)
{
	if (load_texture(data, &data->tab_textures[0].north, data->file.north))
		exit_mlx(data, NO_PB, 2);
	if (load_texture(data, &data->tab_textures[0].south, data->file.south))
		exit_mlx(data, SO_PB, 3);
	if (load_texture(data, &data->tab_textures[0].east, data->file.east))
		exit_mlx(data, EA_PB, 4);
	if (load_texture(data, &data->tab_textures[0].west, data->file.west))
		exit_mlx(data, WE_PB, 5);
}

void	load_textures(t_data *data)
{
    load_wall(data);
	load_tree(data);
    load_house(data);
    load_labo_r(data);
    load_labo_l(data);
    load_river(data);
}
