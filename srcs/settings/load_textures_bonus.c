#include "headers.h"

void    load_tree(t_data *data)
{
	if (load_texture(data, &data->tab_textures[1].north, "assets/textures/sprite_pokemon/tree.xpm"))
		exit_mlx(data, NO_PB, 2);
	if (load_texture(data, &data->tab_textures[1].south, "assets/textures/sprite_pokemon/tree.xpm"))
		exit_mlx(data, SO_PB, 3);
	if (load_texture(data, &data->tab_textures[1].east,  "assets/textures/sprite_pokemon/tree.xpm"))
		exit_mlx(data, EA_PB, 4);
	if (load_texture(data, &data->tab_textures[1].west,  "assets/textures/sprite_pokemon/tree.xpm"))
		exit_mlx(data, WE_PB, 5);
}

void    load_house(t_data *data)
{
	if (load_texture(data, &data->tab_textures[2].north, "assets/textures/sprite_pokemon/house.xpm"))
		exit_mlx(data, NO_PB, 6);
	if (load_texture(data, &data->tab_textures[2].south, "assets/textures/sprite_pokemon/house_back.xpm"))
		exit_mlx(data, SO_PB, 7);
	if (load_texture(data, &data->tab_textures[2].east, "assets/textures/sprite_pokemon/house_back.xpm"))
		exit_mlx(data, EA_PB, 8);
	if (load_texture(data, &data->tab_textures[2].west, "assets/textures/sprite_pokemon/house_back.xpm"))
		exit_mlx(data, WE_PB, 9);
}

void    load_labo_l(t_data *data)
{
	if (load_texture(data, &data->tab_textures[3].north, "assets/textures/sprite_pokemon/laboL.xpm"))
		exit_mlx(data, NO_PB, 14);
	if (load_texture(data, &data->tab_textures[3].south, "assets/textures/sprite_pokemon/labo_backL.xpm"))
		exit_mlx(data, SO_PB, 15);
	if (load_texture(data, &data->tab_textures[3].east, "assets/textures/sprite_pokemon/labo_corner.xpm"))
		exit_mlx(data, EA_PB, 16);
	if (load_texture(data, &data->tab_textures[3].west, "assets/textures/sprite_pokemon/labo_corner.xpm"))
		exit_mlx(data, WE_PB, 17);
}

void    load_labo_r(t_data *data)
{
	if (load_texture(data, &data->tab_textures[4].north, "assets/textures/sprite_pokemon/laboR.xpm"))
		exit_mlx(data, NO_PB, 10);
	if (load_texture(data, &data->tab_textures[4].south, "assets/textures/sprite_pokemon/labo_backR.xpm"))
		exit_mlx(data, SO_PB, 11);
	if (load_texture(data, &data->tab_textures[4].east, "assets/textures/sprite_pokemon/labo_corner.xpm"))
		exit_mlx(data, EA_PB, 12);
	if (load_texture(data, &data->tab_textures[4].west, "assets/textures/sprite_pokemon/labo_corner.xpm"))
		exit_mlx(data, WE_PB, 13);
}

void    load_river(t_data *data)
{
	if (load_texture(data, &data->tab_textures[5].north, data->file.north))
		exit_mlx(data, NO_PB, 18);
	if (load_texture(data, &data->tab_textures[5].south, data->file.south))
		exit_mlx(data, SO_PB, 19);
	if (load_texture(data, &data->tab_textures[5].east, data->file.east))
		exit_mlx(data, EA_PB, 20);
	if (load_texture(data, &data->tab_textures[5].west, data->file.west))
		exit_mlx(data, WE_PB, 21);
}